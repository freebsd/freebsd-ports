# makefile for use of:	OpenSSH
# Date created:		31 May 2002
# Whom:			dinoex
#
# $FreeBSD: /tmp/pcvs/ports/Mk/bsd.openssl.mk,v 1.15 2004-04-08 10:01:53 dinoex Exp $
#
# Use of 'USE_OPENSSL=yes' includes this Makefile after bsd.ports.pre.mk
#
# the user/port can now set this options in the makefiles.
#
# WITH_OPENSSL_BASE=yes	- Use the version in the base system.
# WITH_OPENSSL_PORT=yes	- Use the port, even if base if up to date
# WITH_OPENSSL_BETA=yes	- Use a snapshot of recent openssl
#
# USE_OPENSSL_RPATH=yes	- pass RFLAGS options in CFLAGS,
#			  needed for ports who don't use LDFLAGS
#
# Overrideable defaults:
#
# OPENSSL_SHLIBVER=	3
# OPENSSL_PORT=		security/openssl
#
# The makefile sets this variables:
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

# honor obsolete options for a bit
.if defined(USE_OPENSSL_BASE) && !defined(WITH_OPENSSL_BASE)
WITH_OPENSSL_BASE=yes
.endif
.if defined(USE_OPENSSL_PORT) && !defined(WITH_OPENSSL_PORT)
WITH_OPENSSL_PORT=yes
.endif

#	if no preference was set, check for an up to date base version
#	but give an installed port preference over it.
.if	!defined(WITH_OPENSSL_BASE) && \
	!defined(WITH_OPENSSL_BETA) && \
	!defined(WITH_OPENSSL_PORT) && \
	!exists(${LOCALBASE}/lib/libcrypto.so) && \
	exists(/usr/include/openssl/opensslv.h)
#	Security: version in base must be 0.9.7d or have fixes
#	http://www.freebsd.org/cgi/cvsweb.cgi/src/crypto/openssl/crypto/opensslv.h
OPENSSLVER!=	${AWK} '/OPENSSL_VERSION_TEXT/ { print $$4; exit }' \
		/usr/include/openssl/opensslv.h
# check for safe versions in the base
.if ${OPENSSLVER} == "0.9.7a-p1" || ${OPENSSLVER} == "0.9.7c-p1" || ${OPENSSLVER} == "0.9.7d"
WITH_OPENSSL_BASE=yes
.endif
.endif

.if defined(WITH_OPENSSL_BASE)
OPENSSLBASE=		/usr
OPENSSLDIR=		/etc/ssl

.if !exists(/usr/lib/libcrypto.so)
check-depends::
	@${ECHO_CMD} "Dependency error: this port requires the OpenSSL library, which is part of"
	@${ECHO_CMD} "the FreeBSD crypto distribution but not installed on your"
	@${ECHO_CMD} "machine. Please see the \"OpenSSL\" section in the handbook"
	@${ECHO_CMD} "(at \"http://www.FreeBSD.org/doc/en_US.ISO8859-1/books/handbook/openssl.html\", for instance)"
	@${ECHO_CMD} "for instructions on how to obtain and install the FreeBSD"
	@${ECHO_CMD} "OpenSSL distribution."
	@${FALSE}
.endif
.if exists(${LOCALBASE}/lib/libcrypto.so)
check-depends::
	@${ECHO_CMD} "Dependency error: this port wants the OpenSSL library from the FreeBSD"
	@${ECHO_CMD} "base system. You can't build against it, while a newer"
	@${ECHO_CMD} "version is installed by a port."
	@${ECHO_CMD} "Please deinstall the port or undefine WITH_OPENSSL_BASE."
	@${FALSE}
.endif

# OpenSSL in the base system may not include IDEA for patent licensing reasons.
.if defined(MAKE_IDEA) && !defined(OPENSSL_IDEA)
OPENSSL_IDEA=		${MAKE_IDEA}
.else
OPENSSL_IDEA?=		NO
.endif

.if ${OPENSSL_IDEA} == "NO"
# XXX This is a hack to work around the fact that /etc/make.conf clobbers
#     our CFLAGS. It might not be enough for all future ports.
.if defined(HAS_CONFIGURE)
CFLAGS+=		-DNO_IDEA
.else
OPENSSL_CFLAGS+=	-DNO_IDEA
.endif
MAKE_ARGS+=		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}"
.endif
OPENSSLRPATH=		/usr/lib:${LOCALBASE}/lib

.else

OPENSSLBASE=		${LOCALBASE}
.if defined(WITH_OPENSSL_BETA)
OPENSSL_SHLIBVER?=	4
OPENSSL_PORT?=		security/openssl-beta
.else
OPENSSL_SHLIBVER?=	3
OPENSSL_PORT?=		security/openssl
.endif
OPENSSLDIR=		${OPENSSLBASE}/openssl
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcrypto.so.${OPENSSL_SHLIBVER}:${PORTSDIR}/${OPENSSL_PORT}
RUN_DEPENDS+=		${LOCALBASE}/lib/libcrypto.so.${OPENSSL_SHLIBVER}:${PORTSDIR}/${OPENSSL_PORT}
OPENSSLRPATH=		${LOCALBASE}/lib

.endif

OPENSSLLIB=		${OPENSSLBASE}/lib
OPENSSLINC=		${OPENSSLBASE}/include

.if defined(USE_OPENSSL_RPATH)
CFLAGS+=		-Wl,-rpath,${OPENSSLRPATH}
.endif
OPENSSL_LDFLAGS+=	-rpath=${OPENSSLRPATH}

.if defined(LDFLAGS)
LDFLAGS+=${OPENSSL_LDFLAGS}
.else
LDFLAGS=${OPENSSL_LDFLAGS}
.endif

CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}"
MAKE_ENV+=		LDFLAGS="${LDFLAGS}"
MAKE_ENV+=		OPENSSLLIB=${OPENSSLLIB} OPENSSLINC=${OPENSSLINC} \
			OPENSSLBASE=${OPENSSLBASE} OPENSSLDIR=${OPENSSLDIR}

### crypto
#RESTRICTED=		"Contains cryptography."

