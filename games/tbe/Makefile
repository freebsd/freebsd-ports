# New ports collection makefile for:	tbe
# Date created:		7 November 2010
# Whom:			johans
#
# $FreeBSD$
#

PORTNAME=	tbe
PORTVERSION=	M7
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/Milestone%20${PORTVERSION:S/M//}
DISTNAME=	TheButterflyEffect-${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The Butterfly Effect

BUILD_DEPENDS=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake corelib gui moc rcc svg uic xml
WRKSRC=		${WRKDIR}/TheButterflyEffect-${PORTVERSION}

post-patch:
		@${REINPLACE_CMD} 's/ make/ ${GMAKE}/' \
			${WRKSRC}/3rdParty/Makefile
		@${REINPLACE_CMD} 's/debug/release link_prl/' ${WRKSRC}/tbe.pro
		@${REINPLACE_CMD} 's:BINARY_DIRECTORY+":"${DATADIR}:' \
			${WRKSRC}/src/tbe_global.h

pre-build:
		# This is supposedly done by the ./configure script
		@cd ${WRKSRC}/3rdParty && ${GMAKE}
		@cd ${WRKSRC} && ${QMAKE}

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
		@${MKDIR} ${DATADIR}
		@cd ${WRKSRC} && ${PAX} -rw images levels ${DATADIR}

.include <bsd.port.mk>
