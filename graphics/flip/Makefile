# ex:ts=8
# Ports collection makefile for:	flip
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flip
PORTVERSION=	2.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.reptilelabour.com/software/files/flip/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Load a sequence of TIFF files and play them back at a target frame rate

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode

WRKSRC=		${WRKDIR}/${DISTNAME:R}

USE_QT_VER=	3
USE_REINPLACE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}"

post-patch:
	@${REINPLACE_CMD} -e  's|warn_on release|warn_on thread release|g ; \
		 s|/usr/X11R6/include|$${LOCALBASE}/include|g ; \
		 s|= -ltiff|= -L$${LOCALBASE}/lib -ltiff|g' ${WRKSRC}/FLIP.pro
	@${REINPLACE_CMD} -e \
		's|/usr/bin|${LOCALBASE}/bin|g' ${WRKSRC}/Config.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ FLIP.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flip ${PREFIX}/bin

.include <bsd.port.mk>
