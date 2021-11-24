--- chrome/browser/resources/settings/appearance_page/appearance_page.js.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/resources/settings/appearance_page/appearance_page.js
@@ -150,7 +150,7 @@ Polymer({
     'themeChanged_(' +
         'prefs.extensions.theme.id.value, useSystemTheme_, isForcedTheme_)',
 
-    // <if expr="is_linux and not chromeos">
+    // <if expr="is_bsd and not chromeos">
     // NOTE: this pref only exists on Linux.
     'useSystemThemePrefChanged_(prefs.extensions.theme.use_system.value)',
     // </if>
@@ -239,7 +239,7 @@ Polymer({
     this.appearanceBrowserProxy_.useDefaultTheme();
   },
 
-  // <if expr="is_linux and not chromeos">
+  // <if expr="is_bsd and not chromeos">
   /**
    * @param {boolean} useSystemTheme
    * @private
@@ -322,10 +322,10 @@ Polymer({
     }
 
     let i18nId;
-    // <if expr="is_linux and not chromeos and not lacros">
+    // <if expr="is_posix and not chromeos and not lacros">
     i18nId = useSystemTheme ? 'systemTheme' : 'classicTheme';
     // </if>
-    // <if expr="not is_linux or chromeos or lacros">
+    // <if expr="not is_posix or chromeos or lacros">
     i18nId = 'chooseFromWebStore';
     // </if>
     this.themeSublabel_ = this.i18n(i18nId);
