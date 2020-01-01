# $FreeBSD$
#
# Handle dependency on *ssl ports.
#
# Feature:	SSL_DEFAULT
# Usage:	USES=ssl
# Valid ARGS:	none (build and run), build, run
#
# The user can choose which ssl library he wants with:
#
# DEFAULT_VERSIONS+=	ssl=<openssl variant>
#
# Variants being base, openssl, libressl, and libressl-devel.
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

.if !empty(ssl_ARGS:Nbuild:Nrun)
IGNORE=	"USES=ssl invalid arguments ${ssl_ARGS}."
.endif

.if empty(ssl_ARGS) || (!empty(ssl_ARGS:Mbuild) && !empty(ssl_ARGS:Mrun))
_SSL_BUILD_DEP=	1
_SSL_RUN_DEP=	1
.elif !empty(ssl_ARGS:Mbuild)
_SSL_BUILD_DEP=	1
.elif !empty(ssl_ARGS:Mrun)
_SSL_RUN_DEP=	1
.endif

.if defined(BROKEN_SSL) && ${BROKEN_SSL:M${SSL_DEFAULT}}
.  if defined(BROKEN_SSL_REASON_${SSL_DEFAULT})
BROKEN=	does not build with DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT}: ${BROKEN_SSL_REASON_${SSL_DEFAULT}}
.  elif defined(BROKEN_SSL_REASON)
BROKEN=	does not build with DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT}: ${BROKEN_SSL_REASON}
.  else
BROKEN=	does not build with DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT}
.  endif
.endif

.if defined(IGNORE_SSL) && ${IGNORE_SSL:M${SSL_DEFAULT}}
.  if defined(IGNORE_SSL_REASON_${SSL_DEFAULT})
IGNORE=	not compatible DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT}: ${IGNORE_SSL_REASON_${SSL_DEFAULT}}
.  elif defined(IGNORE_SSL_REASON)
IGNORE=	not compatible DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT}: ${IGNORE_SSL_REASON}
.  else
IGNORE=	not compatible DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT}
.  endif
.endif

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

.else # ${SSL_DEFAULT} != base

OPENSSLBASE=		${LOCALBASE}

OPENSSL_PORT=		security/${SSL_DEFAULT}

# Get OPENSSL_SHLIBVER from the port
.sinclude <${PORTSDIR}/${OPENSSL_PORT}/version.mk>

.  if !defined(OPENSSL_SHLIBVER)
.error You are using an unsupported SSL provider ${SSL_DEFAULT}
.  endif

OPENSSLDIR?=		${OPENSSLBASE}/openssl
.  if defined(_SSL_BUILD_DEP)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcrypto.so.${OPENSSL_SHLIBVER}:${OPENSSL_PORT}
.  endif
.  if defined(_SSL_RUN_DEP)
RUN_DEPENDS+=		${LOCALBASE}/lib/libcrypto.so.${OPENSSL_SHLIBVER}:${OPENSSL_PORT}
.  endif
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
