# New ports collection makefile for:	pm3-net
# Date created:		6 Feb 2000
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pm3-net
PORTVERSION=	1.1.15
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	jdp@FreeBSD.org
COMMENT=	Low-level networking libraries for the PM3 Modula-3 distribution

BUILD_DEPENDS=	${L1}libm3${L2}:${PORTSDIR}/lang/pm3-base
RUN_DEPENDS=	${L1}libm3${L2}:${PORTSDIR}/lang/pm3-base
DEPENDS=	${PORTSDIR}/lang/pm3-base:configure

DIST_SUBDIR=	pm3
INSTALL_TARGET=	all
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		TARGETDIR=${TARGETDIR} WORDSIZE=${WORDSIZE}
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../pm3-base/work/pm3-${PORTVERSION}

BUILDDIRS=	network/tcplibs/tcp \
		network/tcplibs/tcpextras \
		network/udp
L1=		${PREFIX}/lib/m3/${TARGET}/
SOVERSION=	7
# hack to work around bsd.port.mk problem
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
L2=		.so.${SOVERSION}.0
TARGET=		FreeBSD2
TARGETDIR=	freebsd-2
WORDSIZE=	32
.elif ${ARCH} == "i386"
L2=		.so.${SOVERSION}
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
IGNORE=		Not supported on older versions of FreeBSD/Alpha
.endif
CFLAGS+=	-mieee
L2=		.so.${SOVERSION}
TARGET=		FBSD_ALPHA
TARGETDIR=	fbsd-alpha
WORDSIZE=	64
.endif

.if !defined(TARGET)
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
	@${MKDIR} ${PREFIX}/share/pm3-net
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/pm3-net

.include <bsd.port.post.mk>
