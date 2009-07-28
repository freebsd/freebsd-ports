# New ports collection makefile for:	windstille
# Date created:		14 Jun 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	windstille
PORTVERSION=	0.3.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	BERLIOS CENKES

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Classic 2D jump-n-shoot game

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		physfs.1:${PORTSDIR}/devel/physfs \
		ogg.6:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		png.5:${PORTSDIR}/graphics/png \
		GLEW.1:${PORTSDIR}/graphics/glew \
		squirrel.0:${PORTSDIR}/lang/squirrel \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_SCONS=	yes
USE_GL=		gl
USE_SDL=	sdl image
USE_BISON=	build
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
