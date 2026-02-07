# (X)Emacs: -*- mode: python; coding: latin-1; -*-
# TAB-Completion for Jython with JLine console.
# JLineCompleter.py,v 1.5 2007/09/28 09:13:10 martin Exp

# Jython + JLine + Tab-Completion Micro-Howto:
#
# JLine is a 99% pure Java console library similar to GNU Readline but
# with an incompatible API.  Jython 2.2 already contains some support
# for JLine.  For basic line editing and a command history it suffices
# to set python.console=org.python.util.JLineConsole either in the
# Jython registry or in the ~/.jython file.  Obviously the JLine
# jarfile must be in your classpath.
#
# Unfortunately Jython does not support tab-completion for JLine yet.
# It can be enabled by importing this file - however this needs
# patches.  To summarize prerequisites:
#
#   1. You need a patch to JLine that adds the
#      ConsoleRunner.getReader() method.  On FreeBSD build jline with
#      option WITH_JLINEPATCH enabled.
#
#   2. You must wrap the entry point to Jython with a
#      jline.ConsoleRunner instance. You do this by editing
#      /usr/local/bin/jython and inserting an extra argument
#      "jline.ConsoleRunner" right before the "org.python.util.jython"
#      argument.
#
#   3. While there don't forget to add
#      /usr/local/share/java/classes/jline.jar to the classpath.
#
#   4. You must set python.console="" in the ~/.jython file.  You
#      don't want Jython to create another console instance running
#      behind the wrapper console.
#
#   5. Finally you have to import this module.  You may want to do a
#      "import user" instead and code the "import JLineCompleter"
#      inside ~/.pythonrc.py instead.
#
# If that is too much hassle - just wait for my upcoming
# devel/libreadline-java port!


"""Word completion for JLine

The completer completes keywords, built-ins and globals in a
selectable namespace (which defaults to __main__); when completing
NAME.NAME..., it evaluates (!) the expression up to the last dot and
completes its attributes.

It's very cool to do "import sys" type "sys.", hit the
completion key (twice), and see the list of names defined by the
sys module!

Notes:

- Exceptions raised by the completer function are *ignored* (and
generally cause the completion to fail).  This is a feature -- since
readline sets the tty device in raw (or cbreak) mode, printing a
traceback wouldn't work well without some complicated hoopla to save,
reset and restore the tty state.

- The evaluation of the NAME.NAME... form may cause arbitrary
application defined code to be executed if an object with a
__getattr__ hook is found.  Since it is the responsibility of the
application (or the user) to enable this feature, I consider this an
acceptable risk.  More complicated expressions (e.g. function calls or
indexing operations) are *not* evaluated.

This module is a slightly hacked version of the CPython 2.5 module
rlcompleter.  It is therefore under the PSF (Python Software
Foundation) license.
"""

__all__ = ["JLineCompleter"]
__license__ = "PSF"

try:
    import jline
except ImportError:
    raise ImportError("Make sure you have the jline.jar in classpath!")
if not jline.__file__:
    jline.__file__ = "jline.jar"  # Keep the site module from throwing.
import __builtin__
import keyword
import re


# @sig public class JythonCompleter extends java.lang.Object implements
# jline.Completor, org.python.core.PyProxy, org.python.core.ClassDictInit
class JLineCompleter(jline.Completor):
    def __init__(self, namespace = None):
        """Create a new completer for the command line.

        Completer([namespace]) -> completer instance.

        If unspecified, the default namespace where completions are performed
        is __main__ (technically, __main__.__dict__). Namespaces should be
        given as dictionaries.

        Completer instances should be used as the completion mechanism of
        JLine via the jline.ConsoleRunner.completors system property.
        """

        if namespace and not isinstance(namespace, dict):
            raise TypeError,'namespace must be a dictionary'

        # Don't bind to namespace quite yet, but flag whether the user wants a
        # specific namespace or to use __main__.__dict__. This will allow us
        # to bind to __main__.__dict__ at completion time, not now.
        if namespace is None:
            self.use_main_ns = 1
        else:
            self.use_main_ns = 0
            self.namespace = namespace

    # @sig int complete(String buffer, int cursor, List candidates)
    def complete(self, buffer, cursor, candidates):
        """Return the list of possible completions for 'buffer'."""
        if self.use_main_ns:
            import __main__
            self.namespace = __main__.__dict__

        # Determine the text to be expanded:
        text = buffer[:cursor]
        start = 0
        for i in xrange(cursor - 1, -1, -1):
            ch = text[i]
            if not (ch.isalnum() or ch == '.' or ch == '_'):
                start = i + 1
                break
        text = text[start:]
        try:
            if "." in text:
                self.matches = self.attr_matches(text)
            else:
                self.matches = self.global_matches(text)
            for m in self.matches:
                candidates.add(m)
            if self.matches:
                return start
            else:
                return -1
        except (AttributeError, IndexError, NameError):
            return -1

    def global_matches(self, text):
        """Compute matches when text is a simple name.

        Return a list of all keywords, built-in functions and names currently
        defined in self.namespace that match.

        """
        matches = []
        n = len(text)
        for list in [keyword.kwlist,
                     __builtin__.__dict__,
                     self.namespace]:
            for word in list:
                if word[:n] == text and word != "__builtins__":
                    matches.append(word)
        return matches

    def attr_matches(self, text):
        """Compute matches when text contains a dot.

        Assuming the text is of the form NAME.NAME....[NAME], and is
        evaluatable in self.namespace, it will be evaluated and its attributes
        (as revealed by dir()) are used as possible completions.  (For class
        instances, class members are also considered.)

        WARNING: this can still invoke arbitrary C code, if an object
        with a __getattr__ hook is evaluated.

        """
        m = re.match(r"(\w+(\.\w+)*)\.(\w*)", text)
        if not m:
            return
        expr, attr = m.group(1, 3)
        object = eval(expr, self.namespace)
        words = dir(object)
        if hasattr(object,'__class__'):
            words.append('__class__')
            words = words + get_class_members(object.__class__)
        matches = []
        n = len(attr)
        for word in words:
            if word[:n] == attr and word != "__builtins__":
                matches.append("%s.%s" % (expr, word))
        return matches

def get_class_members(klass):
    ret = dir(klass)
    if hasattr(klass,'__bases__'):
        for base in klass.__bases__:
            ret = ret + get_class_members(base)
    return ret

try:
    reader = jline.ConsoleRunner.getReader()
    if reader:
        reader.addCompletor(JLineCompleter())
    else:
        raise RuntimeError("jline.ConsoleRunner not active")
except AttributeError:
    # XXX This message is FreeBSD specific!
    raise NotImplementedError("Incompatible JLine version! Set WITH_JLINEPATCH=1 and rebuild the devel/jline port!")

if __name__ == '__main__':
    print "Sorry, no unittests yet!"

#EOF#
