# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	freera
PORTVERSION=	080203
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}%20${PORTNAME}%2B%2B/0.47%20beta
DISTNAME=	${PORTVERSION}_freera++_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Westwood red alert game engine

USE_SDL=	sdl mixer
USE_SCONS=	yes

SCONS_BUILDENV=	${SCONS_ENV} SDL_CONFIG=${SDL_CONFIG}

WRKSRC=		${WRKDIR}/freera++

SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNMAE}
PORTDATA=	*

post-patch:
	@${MV} ${WRKSRC}/SConstruct ${WRKSRC}/SConstruct.orig
	@${CP} ${FILESDIR}/SConstruct ${WRKSRC}/
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/src/video/renderer.cpp \
		${WRKSRC}/src/video/graphicsengine.cpp ${WRKSRC}/src/vfs/vfs.cpp \
		${WRKSRC}/data/settings/files.ini
	@${RM} ${WRKSRC}/data/settings/files.ini.bak
	@${RM} -rf ${WRKSRC}/data/settings/ra/.svn ${WRKSRC}/data/settings/td/.svn

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freera ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
