# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pingus
PORTVERSION=	0.7.6
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free Lemmings-like game

LIB_DEPENDS=	libpng.so:graphics/png \
		libboost_signals.so:devel/boost-libs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib iconv scons tar:bzip2
USE_GL=		gl
USE_SDL=	sdl image mixer
LIBS+=		${ICONV_LIB}
MAKE_ARGS+=	LIBS="${LIBS}"

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
