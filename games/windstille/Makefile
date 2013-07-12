# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	windstille
PORTVERSION=	0.3.0
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	BERLIOS CENKES

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Classic 2D jump-n-shoot game

LIB_DEPENDS=	physfs:${PORTSDIR}/devel/physfs \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		png15:${PORTSDIR}/graphics/png \
		squirrel:${PORTSDIR}/lang/squirrel \
		freetype:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_SCONS=	yes
USE_OPENAL=	al
USE_GL=		glew
USE_SDL=	sdl image
USES=		bison
MAKE_JOBS_SAFE=	yes

post-extract:
	@${RM} -rf ${WRKSRC}/lib ${WRKSRC}/data/music/*

post-patch:
	@cd ${WRKSRC}/src/ && ${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' \
		particles/deform_drawer.cpp windstille_main.cpp objects/shockwave.cpp
	@${REINPLACE_CMD} -e "s|glew|GLEW|;/LIBS/s|'squirrel'|'squirrel', 'sqstdlib'|"\
		${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e 's|PHYSFS_getBaseDir()|""|' ${WRKSRC}/src/windstille_main.cpp
	@${REINPLACE_CMD} -e 's|bison|${LOCALBASE}/bin/&|' ${WRKSRC}/tools/SConscript
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|; s|freetype-config|${LOCALBASE}/bin/&|' \
		${WRKSRC}/SConstruct ${WRKSRC}/src/SConscript

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/windstille ${PREFIX}/bin/
	${INSTALL} -d ${DATADIR}/
	@cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR}/

.include <bsd.port.mk>
