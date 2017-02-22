--- src/bootstrap/compile.rs.orig	2017-02-09 01:37:48 UTC
+++ src/bootstrap/compile.rs
@@ -187,7 +187,7 @@ pub fn rustc<'a>(build: &'a Build, targe
     cargo.env("CFG_RELEASE", &build.release)
          .env("CFG_RELEASE_CHANNEL", &build.config.channel)
          .env("CFG_VERSION", &build.version)
-         .env("CFG_PREFIX", build.config.prefix.clone().unwrap_or(String::new()))
+         .env("CFG_PREFIX", build.config.prefix.clone().unwrap_or(PathBuf::new()))
          .env("CFG_LIBDIR_RELATIVE", "lib");
 
     // If we're not building a compiler with debugging information then remove
