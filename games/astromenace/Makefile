# Created by: Oleg Alexeenkov
# $FreeBSD$

PORTNAME=	astromenace
PORTVERSION=	1.4.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hardcore 3D space shooter with spaceship upgrade possibilities

LICENSE=	GPLv3+ CC-BY-SA-4.0 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/licenses/GPL-3.0.txt
LICENSE_FILE_CC-BY-SA-4.0=${WRKSRC}/licenses/CC-BY-SA-4.0.txt
LICENSE_FILE_OFL11=	${WRKSRC}/licenses/OFL-1.1.txt

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis \
		libfreetype.so:print/freetype2

USE_GITHUB=	yes
GH_ACCOUNT=	viewizard

USES=		cmake compiler:c++11-lib dos2unix gl openal:al,alut
DOS2UNIX_FILES=	CMakeLists.txt src/config/config.cpp
USE_GL=		gl glu
USE_SDL=	sdl2
CMAKE_ARGS=	-DDATADIR="${DATADIR}"
LLD_UNSAFE=	yes

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gamedata.vfs ${STAGEDIR}${DATADIR}/
.for s in 64 128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/
	${INSTALL_DATA} ${WRKSRC}/share/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/${PORTNAME}.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/share/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata/
	${INSTALL_DATA} ${WRKSRC}/share/${PORTNAME}.appdata.xml \
		${STAGEDIR}${PREFIX}/share/appdata/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
