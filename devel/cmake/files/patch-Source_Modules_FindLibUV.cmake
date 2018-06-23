Sent upstream: https://gitlab.kitware.com/cmake/cmake/merge_requests/2169

commit 6ad09a5d14ef497cca653d303c3849f83aa0aca3
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Sat Jun 23 20:30:07 2018 +0200

    FindLibUV: Also check uv/version.h for version detection

    Starting with libuv 1.21.0, libuv's headers were moved into a uv/ directory.
    Make FindLibUV aware of the file's new location for configuration to work.

    Upstream change: https://github.com/libuv/libuv/pull/1429

--- Source/Modules/FindLibUV.cmake
+++ Source/Modules/FindLibUV.cmake
@@ -63,6 +63,8 @@ mark_as_advanced(LibUV_INCLUDE_DIR)
 set(_LibUV_H_REGEX "#[ \t]*define[ \t]+UV_VERSION_(MAJOR|MINOR|PATCH)[ \t]+[0-9]+")
 if(LibUV_INCLUDE_DIR AND EXISTS "${LibUV_INCLUDE_DIR}/uv-version.h")
   file(STRINGS "${LibUV_INCLUDE_DIR}/uv-version.h" _LibUV_H REGEX "${_LibUV_H_REGEX}")
+elseif(LibUV_INCLUDE_DIR AND EXISTS "${LibUV_INCLUDE_DIR}/uv/version.h")
+  file(STRINGS "${LibUV_INCLUDE_DIR}/uv/version.h" _LibUV_H REGEX "${_LibUV_H_REGEX}")
 elseif(LibUV_INCLUDE_DIR AND EXISTS "${LibUV_INCLUDE_DIR}/uv.h")
   file(STRINGS "${LibUV_INCLUDE_DIR}/uv.h" _LibUV_H REGEX "${_LibUV_H_REGEX}")
 else()
