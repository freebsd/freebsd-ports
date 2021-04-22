--- rts/build/cmake/UtilVersion.cmake.orig	2020-12-26 12:45:43 UTC
+++ rts/build/cmake/UtilVersion.cmake
@@ -138,56 +138,7 @@ EndMacro (get_version_from_file)
 # Sets the following vars:
 # - ${prefix}_VERSION
 Macro    (fetch_spring_version dir prefix)
-	# unset the vars
-	Set(${prefix}_VERSION)
-	Set(${prefix}_VERSION-NOTFOUND)
-
-	If     (EXISTS "${dir}/.git")
-		# Try to fetch version through git
-		If     (NOT GIT_FOUND)
-			Message(FATAL_ERROR "Git repository detected, but git executable not found; failed to fetch ${prefix} version.")
-		EndIf  (NOT GIT_FOUND)
-
-		# Fetch git version info
-		git_util_describe(${prefix}_Describe ${dir} "*")
-		If     (NOT ${prefix}_Describe)
-			Message(FATAL_ERROR "Failed to fetch git-describe for ${prefix}.")
-		EndIf  (NOT ${prefix}_Describe)
-		If     ("${${prefix}_Describe}" MATCHES "^${VERSION_REGEX_RELEASE}$")
-			Set(${prefix}_IsRelease TRUE)
-		Else   ("${${prefix}_Describe}" MATCHES "^${VERSION_REGEX_RELEASE}$")
-			Set(${prefix}_IsRelease FALSE)
-		EndIf  ("${${prefix}_Describe}" MATCHES "^${VERSION_REGEX_RELEASE}$")
-		If     (NOT ${prefix}_IsRelease)
-			# We always want the long git-describe output on non-releases
-			# for example: 83.0.1-0-g1234567
-			git_util_describe(${prefix}_Describe ${dir} "*" --long)
-		EndIf  (NOT ${prefix}_IsRelease)
-
-		Git_Util_Branch(${prefix}_Branch ${dir})
-		If     (${prefix}_IsRelease)
-			Set(${prefix}_VERSION "${${prefix}_Describe}")
-		Else   (${prefix}_IsRelease)
-			If     (NOT ${prefix}_Branch)
-				Message(FATAL_ERROR "Failed to fetch the git branch for ${prefix}.")
-			EndIf  (NOT ${prefix}_Branch)
-			Set(${prefix}_VERSION "${${prefix}_Describe} ${${prefix}_Branch}")
-		EndIf  (${prefix}_IsRelease)
-		parse_spring_version(${prefix} "${${prefix}_VERSION}")
-		If     ("${${prefix}_Branch}" STREQUAL "master")
-			If     (NOT "${${prefix}_COMMITS}" STREQUAL "" OR NOT "${${prefix}_HASH}" STREQUAL "")
-				Message(AUTHOR_WARNING "Commit without a version tag found on branch master for ${prefix}; this indicates a tagging/branching/push error.")
-			EndIf  (NOT "${${prefix}_COMMITS}" STREQUAL "" OR NOT "${${prefix}_HASH}" STREQUAL "")
-		EndIf  ("${${prefix}_Branch}" STREQUAL "master")
-	Else   (EXISTS "${dir}/.git")
-		# Try to fetch version through VERSION file
-		get_version_from_file(${prefix}_VERSION "${dir}/VERSION")
-		If    (${${prefix}_VERSION-NOTFOUND})
-			Message(FATAL_ERROR "Failed to fetch ${prefix} version.")
-		Else  (${${prefix}_VERSION-NOTFOUND})
-			Message(STATUS "${prefix} version fetched from VERSION file: ${${prefix}_VERSION}")
-		EndIf (${${prefix}_VERSION-NOTFOUND})
-	EndIf  (EXISTS "${dir}/.git")
+	Set(${prefix}_VERSION $ENV{PORTVERSION})
 
 	if(DEFINED ENV{CI})
 		Message(STATUS "Build on travis-ci detected, not checking version (git clone --depth=...)")
