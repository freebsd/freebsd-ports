# New ports collection makefile for:    pvmpov
# Date created:         		22 March 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pvmpov
PORTVERSION=	3.1g.2
CATEGORIES=	graphics parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-3.1g2
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed rendering package for Persistence of Vision Ray Tracer

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/povray31:configure \
		aimk:${PORTSDIR}/net/pvm
RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray31 \
		pvmd:${PORTSDIR}/net/pvm

USE_PERL5_BUILD=yes
USE_XLIB=	yes

WRKSRC=		${WRKDIR}/pvmpov3_1g_2
BUILDBASE=	${WRKSRC}/povray31/source/pvm
PVM_ROOT=	${LOCALBASE}/lib/pvm

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	bin/x-pvmpov \
		lib/pvm/bin/FREEBSD/x-pvmpov

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
		@ ${INSTALL_PROGRAM} ${BUILDBASE}/FREEBSD/x-pvmpov ${PVM_ROOT}/bin/FREEBSD
		@ ${LN} -sf ${PVM_ROOT}/bin/FREEBSD/x-pvmpov ${PREFIX}/bin/x-pvmpov
.if !defined(NOPORTDOCS)
		@ ${MKDIR} ${DOCSDIR}
		@ ${INSTALL_DATA} ${WRKSRC}/doc/PVMPOV-HOWTO.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
