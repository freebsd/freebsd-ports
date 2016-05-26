#
# $FreeBSD$
# bsd.openssl.mk - Support for OpenSSL based ports.
#
# Use of 'USE_OPENSSL=yes' includes this Makefile after bsd.ports.pre.mk
#
# The user/port can now set these options in the Makefiles.
#
# WITH_OPENSSL_BASE=yes	- Use the version in the base system.
# WITH_OPENSSL_PORT=yes	- Use the OpenSSL port, even if base is up to date.
#
# USE_OPENSSL_RPATH=yes	- Pass RFLAGS options in CFLAGS,
#			  needed for ports who don't use LDFLAGS.
#
# Overrideable defaults:
#
# OPENSSL_SHLIBVER=	8
# OPENSSL_PORT=		security/openssl
#
# The Makefile sets these variables:
# OPENSSLBASE		- "/usr" or ${LOCALBASE}
# OPENSSLDIR		- path to openssl
# OPENSSLLIB		- path to the libs
# OPENSSLINC		- path to the matching includes
# OPENSSLRPATH		- rpath for dynamic linker
#
# MAKE_ENV		- extended with the variables above
# CONFIGURE_ENV		- extended with LDFLAGS
# BUILD_DEPENDS		- are added if needed
# RUN_DEPENDS		- are added if needed

OpenSSL_Include_MAINTAINER=	dinoex@FreeBSD.org

#	If no preference was set, check for an installed base version
#	but give an installed port preference over it.
.if	!defined(WITH_OPENSSL_BASE) && \
	!defined(WITH_OPENSSL_PORT) && \
	!exists(${DESTDIR}/${LOCALBASE}/lib/libcrypto.so) && \
	exists(${DESTDIR}/usr/include/openssl/opensslv.h)
WITH_OPENSSL_BASE=yes
.endif

.if defined(WITH_OPENSSL_BASE)
OPENSSLBASE=		/usr
OPENSSLDIR?=		/etc/ssl

.  if !exists(${DESTDIR}/usr/lib/libcrypto.so)
check-depends::
	@${ECHO_CMD} "Dependency error: This port requires the OpenSSL library, which is part of"
	@${ECHO_CMD} "the FreeBSD crypto distribution, but not installed on your"
	@${ECHO_CMD} "machine. Please see the \"OpenSSL\" section in the handbook"
	@${ECHO_CMD} "(at \"http://www.FreeBSD.org/doc/en_US.ISO8859-1/books/handbook/openssl.html\", for instance)"
	@${ECHO_CMD} "for instructions on how to obtain and install the FreeBSD"
	@${ECHO_CMD} "OpenSSL distribution."
	@${FALSE}
.  endif
.  if exists(${LOCALBASE}/lib/libcrypto.so)
check-depends::
	@${ECHO_CMD} "Dependency error: This port wants the OpenSSL library from the FreeBSD"
	@${ECHO_CMD} "base system. You can't build against it, while a newer"
	@${ECHO_CMD} "version is installed by a port."
	@${ECHO_CMD} "Please deinstall the port or undefine WITH_OPENSSL_BASE."
	@${FALSE}
.  endif

# OpenSSL in the base system may not include IDEA for patent licensing reasons.
.  if defined(MAKE_IDEA) && !defined(OPENSSL_IDEA)
OPENSSL_IDEA=		${MAKE_IDEA}
.  else
OPENSSL_IDEA?=		NO
.  endif

.  if ${OPENSSL_IDEA} == "NO"
# XXX This is a hack to work around the fact that /etc/make.conf clobbers
#     our CFLAGS. It might not be enough for all future ports.
.    if defined(HAS_CONFIGURE)
CFLAGS+=		-DNO_IDEA
.    else
OPENSSL_CFLAGS+=	-DNO_IDEA
.    endif
MAKE_ARGS+=		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}"
.  endif

.else # !defined(WITH_OPENSSL_BASE)

OPENSSLBASE=		${LOCALBASE}
.  if	!defined(OPENSSL_PORT) && \
	exists(${DESTDIR}/${LOCALBASE}/lib/libcrypto.so)
# find installed port and use it for dependency
.    if !defined(OPENSSL_INSTALLED)
.      if defined(DESTDIR)
PKGARGS=	-c ${DESTDIR}
.      else
PKGARGS=
.      endif
OPENSSL_INSTALLED!=	${PKG_BIN} ${PKGARGS} which -qo ${LOCALBASE}/lib/libcrypto.so || :
.    endif
.    if defined(OPENSSL_INSTALLED) && ${OPENSSL_INSTALLED} != ""
OPENSSL_PORT=		${OPENSSL_INSTALLED}
OPENSSL_SHLIBFILE!=	${PKG_INFO} -ql ${OPENSSL_INSTALLED} | ${GREP} "^`${PKG_QUERY} "%p" ${OPENSSL_INSTALLED}`/lib/libcrypto.so.[0-9]*$$"
OPENSSL_SHLIBVER?=	${OPENSSL_SHLIBFILE:E}
.    endif
.  endif

# LibreSSL and OpenSSL-BETA specific SHLIBVER
.  if   defined(OPENSSL_PORT) && ${OPENSSL_PORT} == security/libressl
OPENSSL_SHLIBVER?=	37
.  elif defined(OPENSSL_PORT) && ${OPENSSL_PORT} == security/libressl-devel
OPENSSL_SHLIBVER?=	37
.  elif defined(OPENSSL_PORT) && ${OPENSSL_PORT} == security/openssl-devel
OPENSSL_SHLIBVER?=	9
.  endif

# default
OPENSSL_PORT?=		security/openssl
OPENSSL_SHLIBVER?=	8

OPENSSLDIR?=		${OPENSSLBASE}/openssl
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcrypto.so.${OPENSSL_SHLIBVER}:${OPENSSL_PORT}
RUN_DEPENDS+=		${LOCALBASE}/lib/libcrypto.so.${OPENSSL_SHLIBVER}:${OPENSSL_PORT}
OPENSSLRPATH=		${LOCALBASE}/lib

.endif

OPENSSLLIB=		${OPENSSLBASE}/lib
OPENSSLINC=		${OPENSSLBASE}/include

MAKE_ENV+=		OPENSSLBASE=${OPENSSLBASE}
MAKE_ENV+=		OPENSSLDIR=${OPENSSLDIR}
MAKE_ENV+=		OPENSSLINC=${OPENSSLINC}
MAKE_ENV+=		OPENSSLLIB=${OPENSSLLIB}

.if defined(OPENSSLRPATH)
.  if defined(USE_OPENSSL_RPATH)
CFLAGS+=		-Wl,-rpath,${OPENSSLRPATH}
.  endif
MAKE_ENV+=		OPENSSLRPATH=${OPENSSLRPATH}
OPENSSL_LDFLAGS+=	-Wl,-rpath,${OPENSSLRPATH}
.endif

LDFLAGS+=		${OPENSSL_LDFLAGS}

### crypto
#RESTRICTED=		"Contains cryptography."
