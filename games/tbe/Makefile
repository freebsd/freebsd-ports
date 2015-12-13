# $FreeBSD$

PORTNAME=	tbe
PORTVERSION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Milestone%20${PORTVERSION}
DISTNAME=	TheButterflyEffect-M${PORTVERSION}.src

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The Butterfly Effect

BROKEN=		unfetchable
BUILD_DEPENDS=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USES=		qmake gmake tar:tgz
USE_QT4=	corelib gui moc_build rcc_build svg uic_build xml
WRKSRC=		${WRKDIR}/TheButterflyEffect-M${PORTVERSION}rc3

PLIST_FILES=	bin/tbe
PORTDATA=	*

DESKTOP_ENTRIES="The Butterfly Effect" "Inspired by The Incredible Machine" \
		"${DATADIR}/images/tbe-icon.png" \
		"${PREFIX}/bin/tbe" "LogicGame;Game;" false

post-patch:
		@${REINPLACE_CMD} 's/ make/ ${MAKE_CMD}/' \
			${WRKSRC}/3rdParty/Makefile
		@${REINPLACE_CMD} 's/debug/release link_prl/' ${WRKSRC}/tbe.pro
		@${SED} 's:%%DATADIR:QString("${DATADIR}"):'  \
			${WRKSRC}/src/tbe_global.h.in > ${WRKSRC}/src/tbe_global.h
		@${REINPLACE_CMD} -e '/ensure that no-one tries to build/,$$d' \
			${WRKSRC}/tbe.pro

pre-configure:
		# This is supposedly done by the ./configure script
		@cd ${WRKSRC}/3rdParty && ${MAKE_CMD}

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${DATADIR}
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
		cd ${WRKSRC} && ${PAX} -rw images levels ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
