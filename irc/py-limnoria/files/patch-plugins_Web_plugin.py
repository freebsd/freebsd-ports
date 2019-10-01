# https://github.com/ProgVal/Limnoria/pull/1371
# https://github.com/ProgVal/Limnoria/issues/1362
# https://github.com/ProgVal/Limnoria/issues/1359

From 7cf91ad703ab324e38c37fa2976626505f1d569a Mon Sep 17 00:00:00 2001
From: Rodrigo <rodrigo.freebsd@minasambiente.com.br>
Date: Fri, 27 Sep 2019 01:48:36 -0300
Subject: [PATCH 1/3] make clear in logs about charade dep|make behave the same
 way in py3 or py2 without errors in any case (e.g. without charade installed)

---
 plugins/Web/plugin.py | 44 +++++++++++++++++--------------------------
 1 file changed, 17 insertions(+), 27 deletions(-)

diff --git plugins/Web/plugin.py plugins/Web/plugin.py
index 1ac362714..0bdb68a4a 100644
--- plugins/Web/plugin.py
+++ plugins/Web/plugin.py
@@ -150,37 +150,27 @@ def getTitle(self, irc, url, raiseErrors):
         size = conf.supybot.protocols.http.peekSize()
         timeout = self.registryValue('timeout')
         (target, text) = utils.web.getUrlTargetAndContent(url, size=size,
-                timeout=timeout)
-        try:
-            text = text.decode(utils.web.getEncoding(text) or 'utf8',
-                    'replace')
-        except UnicodeDecodeError:
-            pass
-        if minisix.PY3 and isinstance(text, bytes):
-            if raiseErrors:
-                irc.error(_('Could not guess the page\'s encoding. (Try '
-                        'installing python-charade.)'), Raise=True)
-            else:
-                return None
+                                                          timeout=timeout)
+        encoding = utils.web.getEncoding(text)
+        if encoding is None:  # Condition if charade not installed
+            self.log.info('Web plugin TitleSnarfer: Could not guess the page\'s'
+                          ' encoding. (Try installing python-charade.)')
+            encoding = 'utf-8'  # Assume UTF-8 and replace unknown chars to the UTF-8 codec for U+FFFD in the next hop
         try:
+            text = text.decode(utils.web.getEncoding(text) or 'utf-8', 'replace')
             parser = Title()
             parser.feed(text)
-        except UnicodeDecodeError:
-            # Workaround for Python 2
-            # https://github.com/ProgVal/Limnoria/issues/1359
-            parser = Title()
-            parser.feed(text.encode('utf8'))
-        parser.close()
-        title = utils.str.normalizeWhitespace(''.join(parser.data).strip())
-        if title:
-            return (target, title)
-        elif raiseErrors:
-            if len(text) < size:
-                irc.error(_('That URL appears to have no HTML title.'),
-                        Raise=True)
+            parser.close()
+            title = utils.str.normalizeWhitespace(''.join(parser.data).strip())
+            if title:
+                return (target, title)
             else:
-                irc.error(format(_('That URL appears to have no HTML title '
-                                 'within the first %S.'), size), Raise=True)
+                if len(text) < size:
+                    self.log.info('Web plugin TitleSnarfer: '
+                                  'That URL appears to have no HTML title.')
+        except raiseErrors:  # Can use raiseErrors here ?
+            irc.error(_('Web plugin TitleSnarfer encoding errors'),
+                      Raise=True)
 
     @fetch_sandbox
     def titleSnarfer(self, irc, msg, match):

From 16247c5caf59f307b3d6910e31832fe30d0d583a Mon Sep 17 00:00:00 2001
From: Rodrigo <rodrigo.freebsd@minasambiente.com.br>
Date: Fri, 27 Sep 2019 20:12:00 -0300
Subject: [PATCH 2/3] more python2 compatibility

---
 plugins/Web/plugin.py | 18 +++++++++++-------
 1 file changed, 11 insertions(+), 7 deletions(-)

diff --git plugins/Web/plugin.py plugins/Web/plugin.py
index 0bdb68a4a..85c129de3 100644
--- plugins/Web/plugin.py
+++ plugins/Web/plugin.py
@@ -150,16 +150,20 @@ def getTitle(self, irc, url, raiseErrors):
         size = conf.supybot.protocols.http.peekSize()
         timeout = self.registryValue('timeout')
         (target, text) = utils.web.getUrlTargetAndContent(url, size=size,
-                                                          timeout=timeout)
+                timeout=timeout)
         encoding = utils.web.getEncoding(text)
-        if encoding is None:  # Condition if charade not installed
+        if encoding is None: # Condition if charade not installed
             self.log.info('Web plugin TitleSnarfer: Could not guess the page\'s'
                           ' encoding. (Try installing python-charade.)')
-            encoding = 'utf-8'  # Assume UTF-8 and replace unknown chars to the UTF-8 codec for U+FFFD in the next hop
+            encoding = 'utf-8' # Assume UTF-8 and replace unknown chars to the UTF-8 codec for U+FFFD in the next hop
         try:
-            text = text.decode(utils.web.getEncoding(text) or 'utf-8', 'replace')
+            text = text.decode(utils.web.getEncoding(text) or 'utf-8','replace')
             parser = Title()
-            parser.feed(text)
+            try:
+                parser.feed(text)
+            except:
+                parser = Title()
+                parser.feed(bytes(text)) # Explicitly pack to bytes in encoding errors for (more) python2 compatibility
             parser.close()
             title = utils.str.normalizeWhitespace(''.join(parser.data).strip())
             if title:
@@ -168,9 +172,9 @@ def getTitle(self, irc, url, raiseErrors):
                 if len(text) < size:
                     self.log.info('Web plugin TitleSnarfer: '
                                   'That URL appears to have no HTML title.')
-        except raiseErrors:  # Can use raiseErrors here ?
+        except:
             irc.error(_('Web plugin TitleSnarfer encoding errors'),
-                      Raise=True)
+                             Raise=True)
 
     @fetch_sandbox
     def titleSnarfer(self, irc, msg, match):

From 5cac4a3cbda26186a330709901da2633914de415 Mon Sep 17 00:00:00 2001
From: Rodrigo <rodrigo.freebsd@minasambiente.com.br>
Date: Sat, 28 Sep 2019 23:40:44 -0300
Subject: [PATCH 3/3] Include '(target, text) =
 utils.web.getUrlTargetAndContent(url, size=size,timeout=timeout)' in
 try/catch block to avoid thread blocking | send http errors to log

---
 plugins/Web/plugin.py | 23 +++++++++++------------
 1 file changed, 11 insertions(+), 12 deletions(-)

diff --git plugins/Web/plugin.py plugins/Web/plugin.py
index 85c129de3..e67944f29 100644
--- plugins/Web/plugin.py
+++ plugins/Web/plugin.py
@@ -149,14 +149,13 @@ def noIgnore(self, irc, msg):
     def getTitle(self, irc, url, raiseErrors):
         size = conf.supybot.protocols.http.peekSize()
         timeout = self.registryValue('timeout')
-        (target, text) = utils.web.getUrlTargetAndContent(url, size=size,
-                timeout=timeout)
-        encoding = utils.web.getEncoding(text)
-        if encoding is None: # Condition if charade not installed
-            self.log.info('Web plugin TitleSnarfer: Could not guess the page\'s'
-                          ' encoding. (Try installing python-charade.)')
-            encoding = 'utf-8' # Assume UTF-8 and replace unknown chars to the UTF-8 codec for U+FFFD in the next hop
         try:
+            (target, text) = utils.web.getUrlTargetAndContent(url, size=size,timeout=timeout)
+            encoding = utils.web.getEncoding(text)
+            if encoding is None: # Condition if charade not installed
+                self.log.info('Web plugin TitleSnarfer: Could not guess the page\'s'
+                              ' encoding. (Try installing python-charade.)')
+                encoding = 'utf-8' # Assume UTF-8 and replace unknown chars to the UTF-8 codec for U+FFFD in the next hop
             text = text.decode(utils.web.getEncoding(text) or 'utf-8','replace')
             parser = Title()
             try:
@@ -170,11 +169,11 @@ def getTitle(self, irc, url, raiseErrors):
                 return (target, title)
             else:
                 if len(text) < size:
-                    self.log.info('Web plugin TitleSnarfer: '
-                                  'That URL appears to have no HTML title.')
-        except:
-            irc.error(_('Web plugin TitleSnarfer encoding errors'),
-                             Raise=True)
+                    self.log.info('Web plugin TitleSnarfer: <' + url + '> appears to have no HTML title.')
+                else:
+                    self.log.info('Web plugin TitleSnarfer: Could not retrieve title of <' + url + '>')
+        except Exception as e:
+            self.log.info('Web plugin TitleSnarfer: <' + str(e) + '> while trying to process <' + url +'>')
 
     @fetch_sandbox
     def titleSnarfer(self, irc, msg, match):
