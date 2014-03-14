# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	violetland
PORTVERSION=	0.4.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Top-down survival shoot 'em up

LIB_DEPENDS=	libboost_filesystem.so:${PORTSDIR}/devel/boost-libs

USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
USES=		cmake gettext zip
USE_DOS2UNIX=	CMakeLists.txt src/system/utility/FileUtility.cpp
CMAKE_ARGS=	-DDATA_INSTALL_DIR="${DATADIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/set.libList/ s|)| ${LOCALBASE}/lib/libintl.so&|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG README_EN.TXT README_RU.TXT \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
