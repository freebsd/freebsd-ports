# New ports collection makefile for:	Battle Tanks
# Date created:				24 Mar 2008
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	btanks
PORTVERSION=	0.7.5800
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast 2D tank arcade game with multiplayer and split-screen modes

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		openal.0:${PORTSDIR}/audio/openal \
		expat.6:${PORTSDIR}/textproc/expat2 \
		vorbisfile.6:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_SCONS=	yes
USE_SDL=	image sdl
SCONS_BUILDENV=	${SCONS_ENV} LDFLAGS=${PTHREAD_LIBS}
SCONS_ARGS=	prefix=${PREFIX} resources_dir=${DATADIR}
PORTDOCS=	*

OPTIONS=	LUA	"Build with Lua scripting support"	off

.include <bsd.port.pre.mk>

.if defined(WITH_LUA)
USE_LUA=	5.0+
.else
SCONS_ARGS+=	enable_lua=false
.endif

DESKTOP_ENTRIES="Battle Tanks" "${COMMENT}" "" "bt" "Application;Game;" false

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/*[^s].so ${PREFIX}/lib
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/libbt_objects.so ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README-en.txt ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/*.url ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
