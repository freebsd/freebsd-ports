# New ports collection makefile for:	tbe
# Date created:		7 November 2010
# Whom:			johans
#
# $FreeBSD$
#

PORTNAME=	tbe
PORTVERSION=	8.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Milestone%20${PORTVERSION}
DISTNAME=	TheButterflyEffect-m${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The Butterfly Effect

BUILD_DEPENDS=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
USE_QT4=	qmake_build corelib gui moc_build rcc_build svg uic_build xml
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/TheButterflyEffect-m${PORTVERSION}

DESKTOP_ENTRIES="The Butterfly Effect" "Inspired by The Incredible Machine" \
		"${DATADIR}/images/tbe-icon.png" \
		"${PREFIX}/bin/tbe" "LogicGame;Game;" false

post-patch:
		@${REINPLACE_CMD} 's/ make/ ${GMAKE}/' \
			${WRKSRC}/3rdParty/Makefile
		@${REINPLACE_CMD} 's/debug/release link_prl/' ${WRKSRC}/tbe.pro
		@${SED} 's:%%DATADIR:QString("${DATADIR}"):'  \
			${WRKSRC}/src/tbe_global.h.in > ${WRKSRC}/src/tbe_global.h

pre-build:
		# This is supposedly done by the ./configure script
		@cd ${WRKSRC}/3rdParty && ${GMAKE}
		@cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS}

do-install:
		@${MKDIR} ${PREFIX}/bin
		@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
		@${MKDIR} ${DATADIR}
		@cd ${WRKSRC} && ${PAX} -rw images levels ${DATADIR}

.include <bsd.port.mk>
