# $FreeBSD$
#
# Handle dependency on *ssl ports.
#
# Feature:	SSL_DEFAULT
# Usage:	USES=ssl
# Valid ARGS:	none
#
# The use can choose which ssl library he wants with:
#
# DEFAULT_VERSIONS+=	ssl=<openssl variant>
#
# Variants being base, openssl, openssl-devel, libressl, and libressl-devel.
#
# The Makefile sets these variables:
# OPENSSLBASE		- "/usr" or ${LOCALBASE}
# OPENSSLDIR		- path to openssl
# OPENSSLLIB		- path to the libs
# OPENSSLINC		- path to the matching includes
# OPENSSLRPATH		- rpath for dynamic linker
#
# MAKE_ENV		- extended with the variables above
# BUILD_DEPENDS		- are added if needed
# RUN_DEPENDS		- are added if needed
#
# MAINTAINER:	portmgr@FreeBSD.org
#
.if !defined(_INCLUDE_USES_SSL_MK)
_INCLUDE_USES_SSL_MK=	yes

.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if ${SSL_DEFAULT} == base
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
	@${ECHO_CMD} "Please deinstall the port, remove DEFAULT_VERSIONS=ssl=base or undefine WITH_OPENSSL_BASE."
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

.else # ${SSL_DEFAULT} != base

OPENSSLBASE=		${LOCALBASE}

OPENSSL_PORT=		security/${SSL_DEFAULT}

# Get OPENSSL_SHLIBVER from the port
.sinclude <${PORTSDIR}/${OPENSSL_PORT}/version.mk>

.  if !defined(OPENSSL_SHLIBVER)
.error You are using an unsupported SSL provider ${SSL_DEFAULT}
.  endif

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

.endif
