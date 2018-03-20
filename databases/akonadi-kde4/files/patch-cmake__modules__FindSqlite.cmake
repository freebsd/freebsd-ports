commit b60702e0b7041c56a3cb52c209204d28406f3ce5
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Wed Aug 13 14:43:04 2014 +0300

    FindSqlite: Use CMAKE_FLAGS the right way in try_compile().
    
    This fixes f90774f1 ("Check whether Sqlite is compiled with
    SQLITE_ENABLE_UNLOCK_NOTIFY"), so that SQLITE_INCLUDE_DIR is really
    passed to the try_compile() call. So far, it was just a NOP and the
    compilation only worked if sqlite3.h was in a directory the compiler
    uses automatically.
    
    try_compile()'s syntax is a bit complicated, and CMAKE_FLAGS expects a
    series of arguments as if they had been passed to the command line, so
    instead of "CMAKE_FLAGS INCLUDE_DIRECTORIES /some/dir" one needs to use
    "CMAKE_FLAGS -DINCLUDE_DIRECTORIES:PATH=/some/dir".
    
    REVIEW: 119762

diff --git a/cmake/modules/FindSqlite.cmake b/cmake/modules/FindSqlite.cmake
index ad8cdb4..c43a7b5 100644
--- cmake/modules/FindSqlite.cmake
+++ cmake/modules/FindSqlite.cmake
@@ -94,7 +94,7 @@ if(EXISTS ${SQLITE_INCLUDE_DIR}/sqlite3.h)
                 ${CMAKE_BINARY_DIR}/sqlite_check_unlock_notify
                 ${CMAKE_BINARY_DIR}/sqlite_check_unlock_notify.cpp
                 LINK_LIBRARIES ${SQLITE_LIBRARIES}
-                CMAKE_FLAGS INCLUDE_DIRECTORIES ${SQLITE_INCLUDE_DIR})
+                CMAKE_FLAGS "-DINCLUDE_DIRECTORIES:PATH=${SQLITE_INCLUDE_DIR}")
     if (NOT SQLITE_HAS_UNLOCK_NOTIFY)
         message(STATUS "Sqlite ${SQLITE_VERSION} was found, but it is not compiled with -DSQLITE_ENABLE_UNLOCK_NOTIFY")
     endif()
