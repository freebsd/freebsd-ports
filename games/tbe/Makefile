# $FreeBSD$

PORTNAME=	tbe
PORTVERSION=	v0.9.2.1
PORTEPOCH=	1
CATEGORIES=	games

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The Butterfly Effect

BUILD_DEPENDS=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USES=		gmake tar:tgz
USE_QT4=	corelib gui linguist moc_build rcc_build svg uic_build xml

USE_GITHUB=	yes
GH_ACCOUNT=	kaa-ching

INSTALLS_ICONS=	yes
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="The Butterfly Effect" "Inspired by The Incredible Machine" \
		"${DATADIR}/imagery/tbe-icon.png" \
		"${PREFIX}/bin/tbe" "LogicGame;Game;" false

post-patch:
		@${REINPLACE_CMD} 's/ make/ $$(MAKE)/' \
			${WRKSRC}/Makefile
		@${REINPLACE_CMD} 's:/share/games/tbe/:/share/tbe/:' \
			${WRKSRC}/CMakeLists.txt ${WRKSRC}/src/tbe_paths.h

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${DATADIR}
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
		cd ${WRKSRC}/usr && ${PAX} -rw share ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
