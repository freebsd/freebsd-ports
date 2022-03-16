https://gitlab.gnome.org/GNOME/librsvg/-/issues/856

C-style comments (`/* something */`) cannot be nested. Rephrase to
unbreak at least x11/fuzzel.

--- include/librsvg/rsvg.h.orig	2022-03-16 22:38:59 UTC
+++ include/librsvg/rsvg.h
@@ -122,7 +122,7 @@ GType rsvg_error_get_type (void);
  * if the base file is `/foo/bar/baz.svg`, then librsvg will
  * only try to load referenced files (from SVG's
  * `<image>` element, for example, or from content
- * included through XML entities) if those files are in `/foo/bar/*` or in `/foo/bar/*\/.../*`.
+ * included through XML entities) if those files are under `/foo/bar/` or `/foo/bar/.../`.
  * This is so that malicious SVG files cannot include files that are in a directory above.
  *
  * The full set of rules for deciding which URLs may be loaded is as follows;
