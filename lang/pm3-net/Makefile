# New ports collection makefile for:	pm3-net
# Version required:	1.1.13
# Date created:		6 Feb 2000
# Whom:			John Polstra <jdp@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	pm3-net-${VERSION}
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	jdp@polstra.com

BUILD_DEPENDS=	${PREFIX}/lib/m3/${TARGET}/libm3.so.${SOVERSION}:${PORTSDIR}/lang/pm3-base
RUN_DEPENDS=	${PREFIX}/lib/m3/${TARGET}/libm3.so.${SOVERSION}:${PORTSDIR}/lang/pm3-base
DEPENDS=	${PORTSDIR}/lang/pm3-base:configure

DIST_SUBDIR=	pm3
INSTALL_TARGET=	all
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		TARGETDIR=${TARGETDIR} WORDSIZE=${WORDSIZE}
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../pm3-base/work/pm3-${VERSION}

BUILDDIRS=	network/tcplibs/tcp \
		network/tcplibs/tcpextras \
		network/udp
SOVERSION=	7
VERSION=	1.1.13

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
TARGET=		FreeBSD2
TARGETDIR=	freebsd-2
WORDSIZE=	32
.elif ${ARCH} == "i386"
.if ${OSVERSION} < 400011
TARGET=		FreeBSD3
TARGETDIR=	freebsd-3
.else
TARGET=		FreeBSD4
TARGETDIR=	freebsd-4
.endif
WORDSIZE=	32
.elif ${ARCH} == "alpha"
.if ${OSVERSION} < 400011
BROKEN=		Not supported on older versions of FreeBSD/Alpha
.endif
CFLAGS+=	-mieee
TARGET=		FBSD_ALPHA
TARGETDIR=	fbsd-alpha
WORDSIZE=	64
.endif

.if empty(TARGET)
pre-fetch:
	@${ECHO_MSG} "Cannot determine M3 target for this architecture"
	@${FALSE}
.endif

do-build:
	@${ECHO_MSG} "This port does everything in the install step."
	@${ECHO_MSG} "The build step is a no-op."

do-install:
	@for i in ${BUILDDIRS}; do \
	    ${ECHO_MSG} "Building in $${i}"; \
	    cd ${WRKSRC}/$${i} && ${PREFIX}/bin/m3build && \
		${PREFIX}/bin/m3ship; \
	done

.include <bsd.port.post.mk>
