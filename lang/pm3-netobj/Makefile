# New ports collection makefile for:	pm3-netobj
# Date created:		11 Feb 2000
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pm3-netobj
PORTVERSION=	1.1.15
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PM3 distributed objects package supporting robust distributed applications

BUILD_DEPENDS=	${L1}libm3tcp${L2}:${PORTSDIR}/lang/pm3-net \
		${L1}libm3tk${L2}:${PORTSDIR}/lang/pm3-m3tk \
		/nonexistent:${PORTSDIR}/lang/pm3-base:configure
RUN_DEPENDS=	${L1}libm3tcp${L2}:${PORTSDIR}/lang/pm3-net \
		${L1}libm3tk${L2}:${PORTSDIR}/lang/pm3-m3tk

USE_GMAKE=	yes
DIST_SUBDIR=	pm3
INSTALL_TARGET=	all
MAN1=		netobjd.1 stubgen.1
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		INST_TARGET=${INST_TARGET} WORDSIZE=${WORDSIZE}
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../pm3-base/work/pm3-${PORTVERSION}

BUILDDIRS=	network/netobjects/netobj \
		network/netobjects/netobjd \
		network/netobjects/stubgen
PROGS=		bin/netobjd \
		bin/stubgen
L1=		${PREFIX}/lib/m3/${TARGET}/
SOVERSION=	7
# hack to work around bsd.port.mk problem
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
L2=		.so.${SOVERSION}
TARGET=		FreeBSD4
INST_TARGET=	freebsd-4
WORDSIZE=	32
.elif ${ARCH} == "alpha"
CFLAGS+=	-mieee
L2=		.so.${SOVERSION}
TARGET=		FBSD_ALPHA
INST_TARGET=	fbsd-alpha
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
	@for i in ${PROGS}; do ${STRIP_CMD} ${PREFIX}/$$i; done
	@${MKDIR} ${PREFIX}/share/pm3-netobj
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/pm3-netobj

.include <bsd.port.post.mk>
