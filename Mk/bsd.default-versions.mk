# MAINTAINER:	ports@FreeBSD.org
#
# Note: before committing to this file, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
#
# Provide default versions for ports with multiple versions selectable
# by the user.
#
# Users who want to override these defaults can easily do so by defining
# DEFAULT_VERSIONS in their make.conf as follows:
#
#   DEFAULT_VERSIONS=	perl5=5.20 ruby=3.1

.if !defined(_INCLUDE_BSD_DEFAULT_VERSIONS_MK)
_INCLUDE_BSD_DEFAULT_VERSIONS_MK=	yes

LOCALBASE?=	/usr/local

.  for lang in APACHE BDB COROSYNC EBUR128 EMACS FIREBIRD FORTRAN FPC GCC \
	GHOSTSCRIPT GL GO GUILE IMAGEMAGICK JAVA LAZARUS LIBRSVG2 LINUX LLVM \
	LUA LUAJIT MONO MYSQL NINJA NODEJS OPENLDAP PERL5 PGSQL PHP \
	PYCRYPTOGRAPHY PYTHON PYTHON2 RUBY RUST SAMBA SSL TCLTK VARNISH
.    if defined(${lang}_DEFAULT)
ERROR+=	"The variable ${lang}_DEFAULT is set and it should only be defined through DEFAULT_VERSIONS+=${lang:tl}=${${lang}_DEFAULT} in /etc/make.conf"
.    endif
#.undef ${lang}_DEFAULT
.  endfor

.  for lang in ${DEFAULT_VERSIONS}
_l=		${lang:C/=.*//g}
${_l:tu}_DEFAULT=	${lang:C/.*=//g}
.  endfor

# Possible values: 2.4
APACHE_DEFAULT?=	2.4
# Possible values: 5, 18
BDB_DEFAULT?=		5
# Possible values: 2, 3
COROSYNC_DEFAULT?=	3
# Possible values: rust, legacy
.  if empty(ARCH:Naarch64:Namd64:Narmv7:Ni386:Npowerpc64:Npowerpc64le:Npowerpc:Nriscv64)
EBUR128_DEFAULT?=	rust
.  else
EBUR128_DEFAULT?=	legacy
.  endif
# Possible_values: full canna nox devel_full devel_nox
#EMACS_DEFAULT?=	let the flavor be the default if not explicitly set
# Possible values: 3.0, 4.0
FIREBIRD_DEFAULT?=	3.0
# Possible values: gfortran
FORTRAN_DEFAULT?=	gfortran
# Possible values: 3.2.3, 3.3.1
.  if (defined(WANT_FPC_DEVEL) && !empty(WANT_FPC_DEVEL)) || ${ARCH:Maarch64}
FPC_DEFAULT?=		3.3.1
.  else
FPC_DEFAULT?=		3.2.3
.  endif
# Possible values: 12, 13, 14, 15, 16
# (Any other version is completely unsupported and not meant for general use.)
GCC_DEFAULT?=		13
# Possible values: 10
GHOSTSCRIPT_DEFAULT?=	10
# Possible values: mesa-libs, mesa-devel
GL_DEFAULT?=		mesa-libs
# Possible values: 1.20, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26-devel
GO_DEFAULT?=		1.24
# Possible values: 1.8, 2.2, 3.0
GUILE_DEFAULT?=		2.2
# Possible versions: 6, 7
# Possible flavors:  x11, nox11
#                    (defaults to x11 when not specified)
# Format:	     version[-flavor]
# Examples:	     6-nox11, 7
IMAGEMAGICK_DEFAULT?=	7
# Possible values: 8, 11, 17, 18, 19, 20, 21, 22, 23, 24
JAVA_DEFAULT?=		8
# Possible values: 4.2, 4.99
.  if (defined(WANT_LAZARUS_DEVEL) && !empty(WANT_LAZARUS_DEVEL)) || ${ARCH:Maarch64}
LAZARUS_DEFAULT?=	4.99
.  else
LAZARUS_DEFAULT?=	4.2
.  endif
# Possible values: rust, legacy
.  if empty(ARCH:Naarch64:Namd64:Narmv7:Ni386:Npowerpc64:Npowerpc64le:Npowerpc:Nriscv64)
LIBRSVG2_DEFAULT?=	rust
.  else
LIBRSVG2_DEFAULT?=	legacy
.  endif
# Possible values: c7 rl9
.  if ${ARCH:Mi386}
LINUX_DEFAULT?=		c7
.  else
LINUX_DEFAULT?=		rl9
.  endif
# Possible values: 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, -devel (to be used when non-base compiler is required)
LLVM_DEFAULT?=		19
# Possible values: 5.1, 5.2, 5.3, 5.4
LUA_DEFAULT?=		5.4
# Possible values: luajit, luajit-devel, luajit-openresty
.  if ${ARCH:Mpowerpc64*}
LUAJIT_DEFAULT?=	luajit-openresty
.  else
LUAJIT_DEFAULT?=	luajit
.  endif
# Possible values: 5.10, 5.20, 6.8
MONO_DEFAULT?=		5.20
# Possible values: 8.0, 8.4, 9.1, 10.6m, 10.11m, 11.4m, 11.8m
MYSQL_DEFAULT?=		8.0
# Possible values: ninja, samurai
NINJA_DEFAULT?=		ninja
# Possible value: 20, 22, 24, current, lts (Note: current = 24 and lts = 22)
NODEJS_DEFAULT?=	lts
# Possible value: 25, 26
OPENLDAP_DEFAULT?=	26
# Possible values: 5.38, 5.40, 5.42, devel
.  if !exists(${LOCALBASE}/bin/perl) || (!defined(_PORTS_ENV_CHECK) && \
    defined(PACKAGE_BUILDING))
# When changing the default here, make sure the DEPRECATED/EXPIRATION lines in
# the older Perl 5 ports are uncommented at the same time.
PERL5_DEFAULT?=		5.42
.  elif !defined(PERL5_DEFAULT)
# There's no need to replace development versions, like "5.23" with "devel"
# because 1) nobody is supposed to use it outside of poudriere, and 2) it must
# be set manually in /etc/make.conf in the first place, and we're never getting
# in here.
.    if !defined(_PERL5_FROM_BIN)
_PERL5_FROM_BIN!=	${LOCALBASE}/bin/perl -e 'printf "%vd\n", $$^V;'
.    endif
_EXPORTED_VARS+=	_PERL5_FROM_BIN
PERL5_DEFAULT:=		${_PERL5_FROM_BIN:R}
.  endif
# Possible values: 13, 14, 15, 16, 17
PGSQL_DEFAULT?=		17
# Possible values: 8.1, 8.2, 8.3, 8.4, 8.5
PHP_DEFAULT?=		8.3
# Possible values: rust, legacy
.  if empty(ARCH:Naarch64:Namd64:Narmv7:Ni386:Npowerpc64:Npowerpc64le:Npowerpc:Nriscv64)
PYCRYPTOGRAPHY_DEFAULT?=	rust
.  else
PYCRYPTOGRAPHY_DEFAULT?=	legacy
.  endif
# Possible values: 3.9, 3.10, 3.11, 3.12
PYTHON_DEFAULT?=	3.11
# Possible values: 2.7
PYTHON2_DEFAULT?=	2.7
# Possible values: 3.2, 3.3, 3.4, 3.5
RUBY_DEFAULT?=		3.3
# Possible values: rust, rust-nightly
RUST_DEFAULT?=		rust
# Possible values: 4.16, 4.19, 4.20
SAMBA_DEFAULT?=		4.16
# When updating this, please also update the same list in ssl.mk and the checks
# for USES=ssl in qa.sh!
# Possible values: base, openssl, openssl111, openssl31, openssl32, openssl33, libressl, libressl-devel
.  if !defined(SSL_DEFAULT)
#	If no preference was set, check for an installed base version
#	but give an installed port preference over it.
.    if	!defined(SSL_DEFAULT) && \
	!exists(${DESTDIR}/${LOCALBASE}/lib/libcrypto.so) && \
	exists(${DESTDIR}/usr/include/openssl/opensslv.h)
SSL_DEFAULT=	base
.    else
.      if exists(${DESTDIR}/${LOCALBASE}/lib/libcrypto.so)
.        if defined(PKG_BIN)
# find installed port and use it for dependency
.          if !defined(OPENSSL_INSTALLED)
.            if defined(DESTDIR)
PKGARGS=	-c ${DESTDIR}
.            else
PKGARGS=
.            endif
OPENSSL_INSTALLED!=	${PKG_BIN} ${PKGARGS} which -qo ${LOCALBASE}/lib/libcrypto.so || :
.          endif
.          if defined(OPENSSL_INSTALLED) && !empty(OPENSSL_INSTALLED)
SSL_DEFAULT:=		${OPENSSL_INSTALLED:T}
WARNING+=	"You have ${OPENSSL_INSTALLED} installed but do not have DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT} set in your make.conf"
.          endif
.        else
check-makevars::
	@${ECHO_MSG} "You have a ${LOCALBASE}/lib/libcrypto.so file installed, but the framework is unable"
	@${ECHO_MSG} "to determine what port it comes from."
	@${ECHO_MSG} "Add DEFAULT_VERSIONS+=ssl=<openssl package name> to your /etc/make.conf and try again."
	@${FALSE}
.        endif
.      endif
.    endif
# Make sure we have a default in the end
SSL_DEFAULT?=	base
.  endif
# Possible values: 8.6, 9.0
TCLTK_DEFAULT?=		8.6
# Possible values: 6, 7
VARNISH_DEFAULT?=	6

.endif
