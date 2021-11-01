Obtained from:	https://github.com/sbmlteam/libsbml/commit/4f01a15fde1d8afa9eaffb4c13dfc83a3404f183 (based on)

--- src/bindings/python/doc-converter/rewrite_pydoc.py.orig	2020-11-25 11:03:01 UTC
+++ src/bindings/python/doc-converter/rewrite_pydoc.py
@@ -118,7 +118,273 @@ import re
 import sys
 import os
 import textwrap
-from formatter import NullWriter, AbstractFormatter
+try:
+    from formatter import NullWriter, AbstractFormatter
+except Exception:
+    # issue 173 these classes have been removed in 3.10, so 
+    # as per the 3.10 release notes: Existing users should copy whatever 
+    # classes they use into their code. (Contributed by Dong-hee Na and 
+    # Terry J. Reedy in bpo-42299.)
+    #
+    # So here they are:
+
+
+    class NullWriter:
+        """Minimal writer interface to use in testing & inheritance.
+
+        A writer which only provides the interface definition; no actions are
+        taken on any methods.  This should be the base class for all writers
+        which do not need to inherit any implementation methods.
+
+        """
+        def __init__(self): pass
+        def flush(self): pass
+        def new_alignment(self, align): pass
+        def new_font(self, font): pass
+        def new_margin(self, margin, level): pass
+        def new_spacing(self, spacing): pass
+        def new_styles(self, styles): pass
+        def send_paragraph(self, blankline): pass
+        def send_line_break(self): pass
+        def send_hor_rule(self, *args, **kw): pass
+        def send_label_data(self, data): pass
+        def send_flowing_data(self, data): pass
+        def send_literal_data(self, data): pass
+
+    class AbstractFormatter:
+        """The standard formatter.
+
+        This implementation has demonstrated wide applicability to many writers,
+        and may be used directly in most circumstances.  It has been used to
+        implement a full-featured World Wide Web browser.
+
+        """
+
+        #  Space handling policy:  blank spaces at the boundary between elements
+        #  are handled by the outermost context.  "Literal" data is not checked
+        #  to determine context, so spaces in literal data are handled directly
+        #  in all circumstances.
+
+        def __init__(self, writer):
+            self.writer = writer            # Output device
+            self.align = None               # Current alignment
+            self.align_stack = []           # Alignment stack
+            self.font_stack = []            # Font state
+            self.margin_stack = []          # Margin state
+            self.spacing = None             # Vertical spacing state
+            self.style_stack = []           # Other state, e.g. color
+            self.nospace = 1                # Should leading space be suppressed
+            self.softspace = 0              # Should a space be inserted
+            self.para_end = 1               # Just ended a paragraph
+            self.parskip = 0                # Skipped space between paragraphs?
+            self.hard_break = 1             # Have a hard break
+            self.have_label = 0
+
+        def end_paragraph(self, blankline):
+            if not self.hard_break:
+                self.writer.send_line_break()
+                self.have_label = 0
+            if self.parskip < blankline and not self.have_label:
+                self.writer.send_paragraph(blankline - self.parskip)
+                self.parskip = blankline
+                self.have_label = 0
+            self.hard_break = self.nospace = self.para_end = 1
+            self.softspace = 0
+
+        def add_line_break(self):
+            if not (self.hard_break or self.para_end):
+                self.writer.send_line_break()
+                self.have_label = self.parskip = 0
+            self.hard_break = self.nospace = 1
+            self.softspace = 0
+
+        def add_hor_rule(self, *args, **kw):
+            if not self.hard_break:
+                self.writer.send_line_break()
+            self.writer.send_hor_rule(*args, **kw)
+            self.hard_break = self.nospace = 1
+            self.have_label = self.para_end = self.softspace = self.parskip = 0
+
+        def add_label_data(self, format, counter, blankline = None):
+            if self.have_label or not self.hard_break:
+                self.writer.send_line_break()
+            if not self.para_end:
+                self.writer.send_paragraph((blankline and 1) or 0)
+            if isinstance(format, str):
+                self.writer.send_label_data(self.format_counter(format, counter))
+            else:
+                self.writer.send_label_data(format)
+            self.nospace = self.have_label = self.hard_break = self.para_end = 1
+            self.softspace = self.parskip = 0
+
+        def format_counter(self, format, counter):
+            label = ''
+            for c in format:
+                if c == '1':
+                    label = label + ('%d' % counter)
+                elif c in 'aA':
+                    if counter > 0:
+                        label = label + self.format_letter(c, counter)
+                elif c in 'iI':
+                    if counter > 0:
+                        label = label + self.format_roman(c, counter)
+                else:
+                    label = label + c
+            return label
+
+        def format_letter(self, case, counter):
+            label = ''
+            while counter > 0:
+                counter, x = divmod(counter-1, 26)
+                # This makes a strong assumption that lowercase letters
+                # and uppercase letters form two contiguous blocks, with
+                # letters in order!
+                s = chr(ord(case) + x)
+                label = s + label
+            return label
+
+        def format_roman(self, case, counter):
+            ones = ['i', 'x', 'c', 'm']
+            fives = ['v', 'l', 'd']
+            label, index = '', 0
+            # This will die of IndexError when counter is too big
+            while counter > 0:
+                counter, x = divmod(counter, 10)
+                if x == 9:
+                    label = ones[index] + ones[index+1] + label
+                elif x == 4:
+                    label = ones[index] + fives[index] + label
+                else:
+                    if x >= 5:
+                        s = fives[index]
+                        x = x-5
+                    else:
+                        s = ''
+                    s = s + ones[index]*x
+                    label = s + label
+                index = index + 1
+            if case == 'I':
+                return label.upper()
+            return label
+
+        def add_flowing_data(self, data):
+            if not data: return
+            prespace = data[:1].isspace()
+            postspace = data[-1:].isspace()
+            data = " ".join(data.split())
+            if self.nospace and not data:
+                return
+            elif prespace or self.softspace:
+                if not data:
+                    if not self.nospace:
+                        self.softspace = 1
+                        self.parskip = 0
+                    return
+                if not self.nospace:
+                    data = ' ' + data
+            self.hard_break = self.nospace = self.para_end = \
+                            self.parskip = self.have_label = 0
+            self.softspace = postspace
+            self.writer.send_flowing_data(data)
+
+        def add_literal_data(self, data):
+            if not data: return
+            if self.softspace:
+                self.writer.send_flowing_data(" ")
+            self.hard_break = data[-1:] == '\n'
+            self.nospace = self.para_end = self.softspace = \
+                        self.parskip = self.have_label = 0
+            self.writer.send_literal_data(data)
+
+        def flush_softspace(self):
+            if self.softspace:
+                self.hard_break = self.para_end = self.parskip = \
+                                self.have_label = self.softspace = 0
+                self.nospace = 1
+                self.writer.send_flowing_data(' ')
+
+        def push_alignment(self, align):
+            if align and align != self.align:
+                self.writer.new_alignment(align)
+                self.align = align
+                self.align_stack.append(align)
+            else:
+                self.align_stack.append(self.align)
+
+        def pop_alignment(self):
+            if self.align_stack:
+                del self.align_stack[-1]
+            if self.align_stack:
+                self.align = align = self.align_stack[-1]
+                self.writer.new_alignment(align)
+            else:
+                self.align = None
+                self.writer.new_alignment(None)
+
+        def push_font(self, font):
+            size, i, b, tt = font
+            if self.softspace:
+                self.hard_break = self.para_end = self.softspace = 0
+                self.nospace = 1
+                self.writer.send_flowing_data(' ')
+            if self.font_stack:
+                csize, ci, cb, ctt = self.font_stack[-1]
+                if size is AS_IS: size = csize
+                if i is AS_IS: i = ci
+                if b is AS_IS: b = cb
+                if tt is AS_IS: tt = ctt
+            font = (size, i, b, tt)
+            self.font_stack.append(font)
+            self.writer.new_font(font)
+
+        def pop_font(self):
+            if self.font_stack:
+                del self.font_stack[-1]
+            if self.font_stack:
+                font = self.font_stack[-1]
+            else:
+                font = None
+            self.writer.new_font(font)
+
+        def push_margin(self, margin):
+            self.margin_stack.append(margin)
+            fstack = filter(None, self.margin_stack)
+            if not margin and fstack:
+                margin = fstack[-1]
+            self.writer.new_margin(margin, len(fstack))
+
+        def pop_margin(self):
+            if self.margin_stack:
+                del self.margin_stack[-1]
+            fstack = filter(None, self.margin_stack)
+            if fstack:
+                margin = fstack[-1]
+            else:
+                margin = None
+            self.writer.new_margin(margin, len(fstack))
+
+        def set_spacing(self, spacing):
+            self.spacing = spacing
+            self.writer.new_spacing(spacing)
+
+        def push_style(self, *styles):
+            if self.softspace:
+                self.hard_break = self.para_end = self.softspace = 0
+                self.nospace = 1
+                self.writer.send_flowing_data(' ')
+            for style in styles:
+                self.style_stack.append(style)
+            self.writer.new_styles(tuple(self.style_stack))
+
+        def pop_style(self, n=1):
+            del self.style_stack[-n:]
+            self.writer.new_styles(tuple(self.style_stack))
+
+        def assert_line_data(self, flag=1):
+            self.nospace = self.hard_break = not flag
+            self.para_end = self.parskip = self.have_label = 0
+    
+
 try:
     from htmllib import HTMLParser
 except Exception:
