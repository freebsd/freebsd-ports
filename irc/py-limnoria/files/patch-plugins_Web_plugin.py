# https://github.com/ProgVal/Limnoria/pull/1371
# https://github.com/ProgVal/Limnoria/issues/1362
# https://github.com/ProgVal/Limnoria/issues/1359

--- plugins/Web/plugin.py.orig	2019-09-29 03:00:58 UTC
+++ plugins/Web/plugin.py
@@ -149,32 +149,31 @@ class Web(callbacks.PluginRegexp):
     def getTitle(self, irc, url, raiseErrors):
         size = conf.supybot.protocols.http.peekSize()
         timeout = self.registryValue('timeout')
-        (target, text) = utils.web.getUrlTargetAndContent(url, size=size,
-                timeout=timeout)
         try:
-            text = text.decode(utils.web.getEncoding(text) or 'utf8',
-                    'replace')
-        except UnicodeDecodeError:
-            pass
-        parser = Title()
-        if minisix.PY3 and isinstance(text, bytes):
-            if raiseErrors:
-                irc.error(_('Could not guess the page\'s encoding. (Try '
-                        'installing python-charade.)'), Raise=True)
+            (target, text) = utils.web.getUrlTargetAndContent(url, size=size,timeout=timeout)
+            encoding = utils.web.getEncoding(text)
+            if encoding is None: # Condition if charade not installed
+                self.log.info('Web plugin TitleSnarfer: Could not guess the page\'s'
+                              ' encoding. (Try installing python-charade.)')
+                encoding = 'utf-8' # Assume UTF-8 and replace unknown chars to the UTF-8 codec for U+FFFD in the next hop
+            text = text.decode(utils.web.getEncoding(text) or 'utf-8','replace')
+            parser = Title()
+            try:
+                parser.feed(text)
+            except:
+                parser = Title()
+                parser.feed(bytes(text)) # Explicitly pack to bytes in encoding errors for (more) python2 compatibility
+            parser.close()
+            title = utils.str.normalizeWhitespace(''.join(parser.data).strip())
+            if title:
+                return (target, title)
             else:
-                return None
-        parser.feed(text)
-        parser.close()
-        title = utils.str.normalizeWhitespace(''.join(parser.data).strip())
-        if title:
-            return (target, title)
-        elif raiseErrors:
-            if len(text) < size:
-                irc.error(_('That URL appears to have no HTML title.'),
-                        Raise=True)
-            else:
-                irc.error(format(_('That URL appears to have no HTML title '
-                                 'within the first %S.'), size), Raise=True)
+                if len(text) < size:
+                    self.log.info('Web plugin TitleSnarfer: <' + url + '> appears to have no HTML title.')
+                else:
+                    self.log.info('Web plugin TitleSnarfer: Could not retrieve title of <' + url + '>')
+        except Exception as e:
+            self.log.info('Web plugin TitleSnarfer: <' + str(e) + '> while trying to process <' + url +'>')
 
     @fetch_sandbox
     def titleSnarfer(self, irc, msg, match):
