--- code/png.py.orig	2014-05-27 07:33:54 UTC
+++ code/png.py
@@ -143,11 +143,12 @@ And now, my famous members
 """
 
 # http://www.python.org/doc/2.2.3/whatsnew/node5.html
-from __future__ import generators
 
+
 __version__ = "0.0.17"
 
 from array import array
+from functools import reduce
 try: # See :pyver:old
     import itertools
 except ImportError:
@@ -188,7 +189,7 @@ _adam7 = ((0, 0, 8, 8),
 
 def group(s, n):
     # See http://www.python.org/doc/2.6/library/functions.html#zip
-    return zip(*[iter(s)]*n)
+    return list(zip(*[iter(s)]*n))
 
 def isarray(x):
     """Same as ``isinstance(x, array)`` except on Python 2.2, where it
@@ -746,15 +747,15 @@ class Writer:
                 a.extend([0]*int(extra))
                 # Pack into bytes
                 l = group(a, spb)
-                l = map(lambda e: reduce(lambda x,y:
-                                           (x << self.bitdepth) + y, e), l)
+                l = [reduce(lambda x,y:
+                                           (x << self.bitdepth) + y, e) for e in l]
                 data.extend(l)
         if self.rescale:
             oldextend = extend
             factor = \
               float(2**self.rescale[1]-1) / float(2**self.rescale[0]-1)
             def extend(sl):
-                oldextend(map(lambda x: int(round(factor*x)), sl))
+                oldextend([int(round(factor*x)) for x in sl])
 
         # Build the first row, testing mostly to see if we need to
         # changed the extend function to cope with NumPy integer types
@@ -769,7 +770,7 @@ class Writer:
         # :todo: Certain exceptions in the call to ``.next()`` or the
         # following try would indicate no row data supplied.
         # Should catch.
-        i,row = enumrows.next()
+        i,row = next(enumrows)
         try:
             # If this fails...
             extend(row)
@@ -779,7 +780,7 @@ class Writer:
             # types, there are probably lots of other, unknown, "nearly"
             # int types it works for.
             def wrapmapint(f):
-                return lambda sl: f(map(int, sl))
+                return lambda sl: f(list(map(int, sl)))
             extend = wrapmapint(extend)
             del wrapmapint
             extend(row)
@@ -1225,7 +1226,7 @@ def from_array(a, mode=None, info={}):
     # first row, which requires that we take a copy of its iterator.
     # We may also need the first row to derive width and bitdepth.
     a,t = itertools.tee(a)
-    row = t.next()
+    row = next(t)
     del t
     try:
         row[0][0]
@@ -1628,12 +1629,12 @@ class Reader:
             spb = 8//self.bitdepth
             out = array('B')
             mask = 2**self.bitdepth - 1
-            shifts = map(self.bitdepth.__mul__, reversed(range(spb)))
+            shifts = list(map(self.bitdepth.__mul__, reversed(list(range(spb)))))
             for o in raw:
-                out.extend(map(lambda i: mask&(o>>i), shifts))
+                out.extend([mask&(o>>i) for i in shifts])
             return out[:width]
 
-        return itertools.imap(asvalues, rows)
+        return map(asvalues, rows)
 
     def serialtoflat(self, bytes, width=None):
         """Convert serial format (byte stream) pixel data to flat row
@@ -1653,7 +1654,7 @@ class Reader:
         spb = 8//self.bitdepth
         out = array('B')
         mask = 2**self.bitdepth - 1
-        shifts = map(self.bitdepth.__mul__, reversed(range(spb)))
+        shifts = list(map(self.bitdepth.__mul__, reversed(list(range(spb)))))
         l = width
         for o in bytes:
             out.extend([(mask&(o>>s)) for s in shifts][:l])
@@ -1884,7 +1885,7 @@ class Reader:
             while True:
                 try:
                     type, data = self.chunk(lenient=lenient)
-                except ValueError, e:
+                except ValueError as e:
                     raise ChunkError(e.args[0])
                 if type == 'IEND':
                     # http://www.w3.org/TR/PNG/#11IEND
@@ -1922,7 +1923,7 @@ class Reader:
             arraycode = 'BH'[self.bitdepth>8]
             # Like :meth:`group` but producing an array.array object for
             # each row.
-            pixels = itertools.imap(lambda *row: array(arraycode, row),
+            pixels = map(lambda *row: array(arraycode, row),
                        *[iter(self.deinterlace(raw))]*self.width*self.planes)
         else:
             pixels = self.iterboxed(self.iterstraight(raw))
@@ -1977,7 +1978,7 @@ class Reader:
         if self.trns or alpha == 'force':
             trns = array('B', self.trns or '')
             trns.extend([255]*(len(plte)-len(trns)))
-            plte = map(operator.add, plte, group(trns, 1))
+            plte = list(map(operator.add, plte, group(trns, 1)))
         return plte
 
     def asDirect(self):
@@ -2034,7 +2035,7 @@ class Reader:
             plte = self.palette()
             def iterpal(pixels):
                 for row in pixels:
-                    row = map(plte.__getitem__, row)
+                    row = list(map(plte.__getitem__, row))
                     yield array('B', itertools.chain(*row))
             pixels = iterpal(pixels)
         elif self.trns:
@@ -2059,11 +2060,11 @@ class Reader:
                     # True/False to 0/maxval (by multiplication),
                     # and add it as the extra channel.
                     row = group(row, planes)
-                    opa = map(it.__ne__, row)
-                    opa = map(maxval.__mul__, opa)
-                    opa = zip(opa) # convert to 1-tuples
+                    opa = list(map(it.__ne__, row))
+                    opa = list(map(maxval.__mul__, opa))
+                    opa = list(zip(opa)) # convert to 1-tuples
                     yield array(typecode,
-                      itertools.chain(*map(operator.add, row, opa)))
+                      itertools.chain(*list(map(operator.add, row, opa))))
             pixels = itertrns(pixels)
         targetbitdepth = None
         if self.sbit:
@@ -2081,7 +2082,7 @@ class Reader:
             meta['bitdepth'] = targetbitdepth
             def itershift(pixels):
                 for row in pixels:
-                    yield map(shift.__rrshift__, row)
+                    yield list(map(shift.__rrshift__, row))
             pixels = itershift(pixels)
         return x,y,pixels,meta
 
@@ -2098,7 +2099,7 @@ class Reader:
         factor = float(maxval)/float(sourcemaxval)
         def iterfloat():
             for row in pixels:
-                yield map(factor.__mul__, row)
+                yield list(map(factor.__mul__, row))
         return x,y,iterfloat(),info
 
     def _as_rescale(self, get, targetbitdepth):
@@ -2111,7 +2112,7 @@ class Reader:
         meta['bitdepth'] = targetbitdepth
         def iterscale():
             for row in pixels:
-                yield map(lambda x: int(round(x*factor)), row)
+                yield [int(round(x*factor)) for x in row]
         if maxval == targetmaxval:
             return width, height, pixels, meta
         else:
@@ -2312,7 +2313,7 @@ except TypeError:
         # Expect to get here on Python 2.2
         def array(typecode, init=()):
             if type(init) == str:
-                return map(ord, init)
+                return list(map(ord, init))
             return list(init)
 
 # Further hacks to get it limping along on Python 2.2
@@ -2711,7 +2712,7 @@ def _main(argv):
         # care about TUPLTYPE.
         greyscale = depth <= 2
         pamalpha = depth in (2,4)
-        supported = map(lambda x: 2**x-1, range(1,17))
+        supported = [2**x-1 for x in range(1,17)]
         try:
             mi = supported.index(maxval)
         except ValueError:
@@ -2748,5 +2749,5 @@ def _main(argv):
 if __name__ == '__main__':
     try:
         _main(sys.argv)
-    except Error, e:
-        print >>sys.stderr, e
+    except Error as e:
+        print(e, file=sys.stderr)
