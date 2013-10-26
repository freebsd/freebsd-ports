# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pvmpov
PORTVERSION=	3.1g.2
PORTREVISION=	5
CATEGORIES=	graphics parallel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-3.1g2.tgz
DISTNAME=	${PORTNAME}-3.1g2
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed rendering package for Persistence of Vision Ray Tracer

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/povray31:configure \
		aimk:${PORTSDIR}/net/pvm
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png
RUN_DEPENDS=	povray31:${PORTSDIR}/graphics/povray31 \
		pvmd:${PORTSDIR}/net/pvm

USES=		perl5
USE_PERL5=	build
USE_XORG=	x11

WRKSRC=		${WRKDIR}/pvmpov3_1g_2
BUILDBASE=	${WRKSRC}/povray31/source/pvm
PVM_ROOT=	${LOCALBASE}/lib/pvm

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	bin/x-pvmpov \
		lib/pvm/bin/FREEBSD/x-pvmpov

NO_STAGE=	yes
pre-configure:
		@ (cd ${WRKDIRPREFIX}${.CURDIR}/../../graphics/povray31/work && \
			 ${TAR} -c -f - povray31 ) \
			| (cd ${WRKSRC} && ${TAR} --unlink -x -f -)
		@ cd ${WRKSRC} && ${PATCH} -p0 -s < pvmpov.patch
		@${REINPLACE_CMD} -i '' -e 's|%LOCALBASE%|${LOCALBASE}|' \
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
