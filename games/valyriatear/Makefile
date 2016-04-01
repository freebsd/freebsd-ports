# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	valyriatear
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open Source J-RPG based on the Hero of Allacrost engine

# Valyria Tear underwent a licensing audit.
# The main game is GPLv2 but artwork/music/fonts are a variety of licenses:
# GPLv2, GPLv3 (with font exception), OFL-1.1, CC0, CC-BY-3, and CC-BY-SA-3.
LICENSE=	GPLv2

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png

USE_GITHUB=	yes
GH_ACCOUNT=	Bertram25
GH_PROJECT=	ValyriaTear

USES=		alias cmake iconv lua:51 openal
CMAKE_ARGS=	-DUSE_PCH_COMPILATION=OFF
USE_SDL=	sdl image ttf
USE_GL=		gl
INSTALLS_ICONS=	yes
LDFLAGS=	-L${LOCALBASE}/lib ${ICONV_LIB} -lintl

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CMAKE_OFF=	-DDISABLE_TRANSLATIONS=ON
NLS_CMAKE_ON=	-DDISABLE_TRANSLATIONS=OFF
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/CMake/Modules/*.cmake

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
