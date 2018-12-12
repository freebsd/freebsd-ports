# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pingus
PORTVERSION=	0.7.6
PORTREVISION=	18
CATEGORIES=	games
MASTER_SITES=	https://mirror.amdmi3.ru/distfiles/

PATCH_SITES=	https://gitlab.com/${PORTNAME}/${PORTNAME}/commit/ \
		https://mirror.amdmi3.ru/distfiles/
PATCHFILES=	fef8cf6512fa.patch:-p1

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Lemmings-like game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/signals2.hpp:devel/boost-libs
LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++11-lib gl iconv scons tar:bzip2
USE_GL=		gl
USE_SDL=	sdl image mixer
LIBS+=		${ICONV_LIB}
MAKE_ARGS=	LIBS="${LIBS}"

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PORTDATA=	*

DESKTOP_ENTRIES="Pingus" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;LogicGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/g_path_manager.set_path("data")/ s|data|${DATADIR}|g' \
		${WRKSRC}/src/pingus/pingus_main.cpp
	@${REINPLACE_CMD} -e '/CheckLib.*iconv/ d' ${WRKSRC}/SConscript

do-install:
	(cd ${WRKSRC}/data && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/data/images/icons/pingus-icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
