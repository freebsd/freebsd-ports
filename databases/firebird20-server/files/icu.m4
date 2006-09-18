dnl AM_PATH_ICU([MINIMUM-VERSION])
dnl Adds support for ICU
AC_DEFUN([AM_PATH_ICU],
[
  rast_lib_icu_major="$1"
  rast_lib_icu_minor="$2"
  rast_lib_icu_version="$1.$2"

  AC_ARG_WITH(icu-config,
  AC_HELP_STRING([--with-icu-config=PATH],[path to icu-config]),
  [
      AC_MSG_RESULT(using $withval for icu-config)
      ICU_CONFIG="$withval"
  ], [
      AC_PATH_PROG(ICU_CONFIG, icu-config, no)
  ])
  HAVE_ICU="no"
  if test "$ICU_CONFIG" != "no"; then
    AC_MSG_CHECKING([ICU version])    
    ICU_VERSION="`$ICU_CONFIG --version`"
    if test $? -eq 0; then
      changequote(<<, >>)
      ICU_MAJOR=`expr "$ICU_VERSION" : '\(.*\)\..*'`
      ICU_MINOR=`expr "$ICU_VERSION" : '.*\.\(.*\)'`
      changequote([, ])
      if expr "$ICU_MAJOR" '>' "$rast_lib_icu_major" > /dev/null ||
         ( expr "$ICU_MAJOR" '=' "$rast_lib_icu_major" > /dev/null &&
           expr "$ICU_MINOR" '>=' "$rast_lib_icu_minor" > /dev/null ); then
        AC_MSG_RESULT([$ICU_VERSION])

        ICU_CPPFLAGS=`$ICU_CONFIG --cppflags`
        ICU_LIBS=`$ICU_CONFIG --ldflags-libsonly`
        ICU_LDFLAGS=`$ICU_CONFIG --ldflags-searchpath`
        AC_SUBST(ICU_CPPFLAGS)
        AC_SUBST(ICU_LIBS)
        AC_SUBST(ICU_LDFLAGS)
        HAVE_ICU="yes"
      else
        AC_MSG_WARN([$ICU_VERSION is too old; $rast_lib_icu_version is required])
      fi
    else
      AC_MSG_WARN([icu-config --version failed])
    fi
  fi
  AC_SUBST(HAVE_ICU)
])
