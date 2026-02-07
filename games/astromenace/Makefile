PORTNAME=	astromenace
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hardcore 3D space shooter with spaceship upgrade possibilities
WWW=		https://www.viewizard.com/

LICENSE=	GPLv3+ CC-BY-SA-4.0 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/licenses/GPL-3.0.txt
LICENSE_FILE_CC-BY-SA-4.0=${WRKSRC}/licenses/CC-BY-SA-4.0.txt
LICENSE_FILE_OFL11=	${WRKSRC}/licenses/OFL-1.1.txt

BROKEN_powerpc64=	fails to build: gamedata/models/models.pack: vw_CreateVFS(): VFS compilation process aborted!

LIB_DEPENDS=	libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libvorbisfile.so:audio/libvorbis \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lib dos2unix gl openal:al,alut sdl
USE_GITHUB=	yes
GH_ACCOUNT=	viewizard
DOS2UNIX_FILES=	CMakeLists.txt
USE_GL=		gl glu
USE_SDL=	sdl2
CMAKE_ARGS=	-DDATADIR="${DATADIR}"
LDFLAGS_i386=	-Wl,-znotext

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
.for s in 64 128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/
	${INSTALL_DATA} ${WRKSRC}/share/${PORTNAME}_${s}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/${PORTNAME}.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/share/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata/
	${INSTALL_DATA} ${WRKSRC}/share/${PORTNAME}.appdata.xml ${STAGEDIR}${PREFIX}/share/appdata/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
