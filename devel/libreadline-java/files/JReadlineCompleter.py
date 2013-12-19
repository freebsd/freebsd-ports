# (X)Emacs: -*- mode: python; coding: latin-1; -*-
# TAB-Completion for Jython with org.python.util.ReadlineConsole.
# JReadlineCompleter.py,v 1.1 2007/09/28 08:18:43 martin Exp
#
# This is rlcompleter.py from CPython 2.5.1 adapted for Jython
# and libreadline-java.
#
# NOTE: Jython >= 2.5 already includes rlcompleter,
#       see http://www.jython.org/docs/library/rlcompleter.html
#       This is useful for older Jython versions only!

"""TAB-completion for Jython + libreadline-java

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

This module is a hacked version of the CPython 2.5 module rlcompleter.
It is under the PSF (Python Software Foundation) license.
"""

# CAUTION: Licensing issues may arise when changing the backend
# library to "GnuReadline" which is under the GPL.
DEFAULTLIB = "Editline"

# Try to give useful hints for any import failure here:
import sys
if not sys.platform.startswith("java"):
    raise EnvironmentError("Module %s is to be used with Jython only!" %
                           (__name__ == "__main__" and __file__ or __name__))
if sys.registry["python.console"] != "org.python.util.ReadlineConsole":
    raise EnvironmentError("You need to set python.console=org.python.util.ReadlineConsole in your ~/.jython file!")
try:
    from org.gnu.readline import Readline, ReadlineLibrary, ReadlineCompleter
except ImportError:
    raise ImportError("Make sure you have libreadline-java.jar in classpath!")
import __builtin__
import atexit
import keyword
import os
import re

__all__ = ["PyCompleter", "JvCompleter"]

Readline.load(
    getattr(ReadlineLibrary, sys.registry["python.console.readlinelib"], "")
    or DEFAULTLIB)
histfile = os.path.join(os.environ["HOME"], ".jyhist")
try:
    Readline.readHistoryFile(histfile)
except:
    print >> sys.stderr, histfile, "not available!"
atexit.register(Readline.writeHistoryFile, histfile)

class PyCompleter:
    def __init__(self, namespace = None):
        """Create a new completer for the command line.

        PyCompleter([namespace]) -> completer instance.

        If unspecified, the default namespace where completions are performed
        is __main__ (technically, __main__.__dict__). Namespaces should be
        given as dictionaries.
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

    def complete(self, text, state):
        """Return the next possible completion for 'text'.

        This is called successively with state == 0, 1, 2, ... until it
        returns None.  The completion should begin with 'text'.

        """
        if self.use_main_ns:
            import __main__
            self.namespace = __main__.__dict__

        try:
            if state == 0:
                if "." in text:
                    matches = self.attr_matches(text)
                else:
                    matches = self.global_matches(text)
                # remove duplicates and sort
                matches = list(set(matches))
                matches.sort()
                self.matches = matches
            return self.matches[state]
        except (AttributeError, IndexError, NameError):
            return None

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


class JvCompleter(ReadlineCompleter):
    """Create a new completer for the command line.

    JvCompleter([completion_callable]) -> completer instance.

    JvCompleter instances should be used as the completion mechanism
    of Readline via the setCompleter() call.
    """
    def __init__(self, realcompleter):
        self.realcompleter = realcompleter
    def completer(self, text, state):
        return self.realcompleter(text, state)


pycompleter = PyCompleter()
jvcompleter = JvCompleter(pycompleter.complete)
Readline.setCompleter(jvcompleter)
Readline.parseAndBind("tab: complete")
try:
    Readline.setCompletionAppendCharacter('\0')
except:
    pass  # Method only available from my java-readline patch.

if __name__ == '__main__':
    print "Sorry, no unit tests yet!"

#EOF#
