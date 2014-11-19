--- configobj.py.orig	2010-02-27 21:36:16 UTC
+++ configobj.py
@@ -1641,7 +1641,7 @@
                             comment = ''
                             try:
                                 value = unrepr(value)
-                            except Exception, e:
+                            except Exception as e:
                                 if type(e) == UnknownType:
                                     msg = 'Unknown name or type in value at line %s.'
                                 else:
@@ -1654,7 +1654,7 @@
                         comment = ''
                         try:
                             value = unrepr(value)
-                        except Exception, e:
+                        except Exception as e:
                             if isinstance(e, UnknownType):
                                 msg = 'Unknown name or type in value at line %s.'
                             else:
@@ -1929,11 +1929,11 @@
                                        raise_errors=True,
                                        file_error=True,
                                        _inspec=True)
-            except ConfigObjError, e:
+            except ConfigObjError as e:
                 # FIXME: Should these errors have a reference
                 #        to the already parsed ConfigObj ?
                 raise ConfigspecError('Parsing configspec failed: %s' % e)
-            except IOError, e:
+            except IOError as e:
                 raise IOError('Reading configspec failed: %s' % e)
         
         self.configspec = configspec
@@ -2189,7 +2189,7 @@
                                         val,
                                         missing=missing
                                         )
-            except validator.baseErrorClass, e:
+            except validator.baseErrorClass as e:
                 if not preserve_errors or isinstance(e, self._vdtMissingValue):
                     out[entry] = False
                 else:
