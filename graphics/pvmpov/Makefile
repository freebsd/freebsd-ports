# New ports collection makefile for:    pvmpov
# Date created:         		22 March 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pvmpov
PORTVERSION=	3.1e.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.luga.de/~flierl/pvmpov/
DISTNAME=	${PORTNAME}-3.1e2
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	nonexistent:${PORTSDIR}/graphics/povray31:configure \
		aimk:${PORTSDIR}/net/pvm
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray31 \
		pvmd:${PORTSDIR}/net/pvm

USE_XLIB=	yes

WRKSRC=		${WRKDIR}/pvmpov3_1e_2
BUILDBASE=	${WRKSRC}/povray31/source/pvm
PVM_ROOT=	${LOCALBASE}/lib/pvm

pre-configure:
		@ (cd ${WRKDIRPREFIX}${.CURDIR}/../../graphics/povray31/work && \
			 ${TAR} -c -f - povray31 ) \
			| (cd ${WRKSRC} && ${TAR} --unlink -x -f -)
		@ cd ${WRKSRC} && ${PATCH} -p0 -s < pvmpov.patch
		@ ${PERL} -pi -e "s|%X11BASE%|${X11BASE}| ; s|%LOCALBASE%|${LOCALBASE}|" \
			${BUILDBASE}/Makefile.aimk

do-build:
		@ cd ${BUILDBASE} && \
			${SETENV} PVM_ROOT=${PVM_ROOT} aimk newxwin

do-install:
		@ ${MKDIR} ${PVM_ROOT}/bin/FREEBSD
		@ ${MKDIR} ${PREFIX}/share/doc/pvmpov
		@ ${INSTALL_PROGRAM} ${BUILDBASE}/FREEBSD/x-pvmpov ${PVM_ROOT}/bin/FREEBSD
		@ ${LN} -sf ${PVM_ROOT}/bin/FREEBSD/x-pvmpov ${PREFIX}/bin/x-pvmpov
.if !defined(NOPORTDOCS)
		@ ${MKDIR} ${PREFIX}/share/doc/pvmpov
		@ ${INSTALL_MAN} ${WRKSRC}/PVM* ${PREFIX}/share/doc/pvmpov
.endif

.include <bsd.port.mk>
