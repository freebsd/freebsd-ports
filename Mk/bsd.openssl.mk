# makefile for use of:	OpenSSH
# Date created:		31 May 2002
# Whom:			dinoex
#
# $FreeBSD: /tmp/pcvs/ports/Mk/bsd.openssl.mk,v 1.6 2003-08-27 10:30:40 dinoex Exp $
#
# this substitutes USE_OPENSSL=yes
# just include this makefile after bsd.ports.pre.mk
#
# the user/port can now set this options in the makefiles.
#
# WITH_OPENSSL_BASE=yes	- Use the version in the base system.
# WITH_OPENSSL_PORT=yes	- Use the port, even if base if up to date
# WITH_OPENSSL_BETA=yes	- Use a snapshot of recent openssl
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
#
# MAKE_ENV		- extended with the variables above
# LIB_DEPENDS		- are added if needed

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
#	Security: version in base must be 0.9.7a
OPENSSLVER!=	${AWK} '/OPENSSL_VERSION_NUMBER/ { print $$3 }' \
		/usr/include/openssl/opensslv.h
.if ${OPENSSLVER} == 0x0090701fL || ${OPENSSLVER} == 0x0090702fL
WITH_OPENSSL_BASE=yes
.endif
.endif

.if defined(WITH_OPENSSL_BASE)
OPENSSLBASE=		/usr
OPENSSLDIR=		/etc/ssl

.if !exists(/usr/lib/libcrypto.so)
.BEGIN:
	@${ECHO_CMD} "This port requires the OpenSSL library, which is part of"
	@${ECHO_CMD} "the FreeBSD crypto distribution but not installed on your"
	@${ECHO_CMD} "machine. Please see the \"OpenSSL\" section in the handbook"
	@${ECHO_CMD} "(at \"http://www.FreeBSD.org/doc/en_US.ISO8859-1/books/handbook/openssl.html\", for instance)"
	@${ECHO_CMD} "for instructions on how to obtain and install the FreeBSD"
	@${ECHO_CMD} "OpenSSL distribution."
	@${FALSE}
.endif
.if exists(${LOCALBASE}/lib/libcrypto.so)
.BEGIN:
	@${ECHO_CMD} "This port wants the OpenSSL library from the FreeBSD"
	@${ECHO_CMD} "base system. You can't build against it, while a newer"
	@${ECHO_CMD} "Version is installed by a port."
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
CFLAGS+=		-Wl,-rpath,/usr/lib:${LOCALBASE}/lib
OPENSSL_LDFLAGS+=	-rpath=/usr/lib:${LOCALBASE}/lib

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
LIB_DEPENDS+=		crypto.${OPENSSL_SHLIBVER}:${PORTSDIR}/${OPENSSL_PORT}
CFLAGS+=		-Wl,-rpath,${LOCALBASE}/lib
OPENSSL_LDFLAGS+=	-rpath=${LOCALBASE}/lib

.endif

OPENSSLLIB=		${OPENSSLBASE}/lib
OPENSSLINC=		${OPENSSLBASE}/include
MAKE_ENV+=		OPENSSLLIB=${OPENSSLLIB} OPENSSLINC=${OPENSSLINC} \
			OPENSSLBASE=${OPENSSLBASE} OPENSSLDIR=${OPENSSLDIR}

.if defined(LDFLAGS) && !empty(LDFLAGS)
LDFLAGS+=${OPENSSL_LDFLAGS}
.else
LDFLAGS=${OPENSSL_LDFLAGS}
.endif

### crypto
#RESTRICTED=		"Contains cryptography."

