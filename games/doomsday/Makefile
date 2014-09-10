# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	doomsday
PORTVERSION=	1.14.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/deng/Doomsday%20Engine/${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Enhanced Doom, Heretic, and Hexen source port

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_SDL=	sdl mixer net
USE_XORG=	x11
USE_PYTHON_BUILD=	yes
USES=		pkgconfig qmake:outsource
USE_QT4=	corelib network opengl moc_build
QMAKE_SOURCE_PATH=	${WRKSRC}/doomsday
CFLAGS+=	-I${LOCALBASE}/include/libpng15
QMAKE_ARGS+=	QMAKE_LFLAGS+="-Wl,--export-dynamic" \
		CONFIG+="deng_notools deng_nosnowberry" \
		SCRIPT_PYTHON=${PYTHON_CMD}
LDFLAGS+=	-lm

OPTIONS_DEFINE=	OPENAL
OPTIONS_SUB=	yes

OPENAL_DESC=	Build OpenAL sound plugin
OPENAL_USES=	openal:al
OPENAL_QMAKE_ON=	CONFIG+=deng_openal
OPENAL_QMAKE_OFF=	CONFIG+=deng_noopenal

PORTSCOUT=	limit:^\d+\.\d+\.\d+$$

.include <bsd.port.pre.mk>
.if ${OPSYS} == DragonFly || (${OPSYS} == FreeBSD && ${OSVERSION} < 1000052)
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

post-patch:
	@${REINPLACE_CMD} 's,share/man,man,' \
		${PATCH_WRKSRC}/doomsday/client/client.pro \
		${PATCH_WRKSRC}/doomsday/server/server.pro
	@${REINPLACE_CMD} 's,python,${PYTHON_CMD},' \
		${PATCH_WRKSRC}/doomsday/config.pri \
		${PATCH_WRKSRC}/doomsday/build/build.pro
	# Removing three non ascii bytes
	@${REINPLACE_CMD} '1s,^...,,' ${WRKSRC}/doomsday/client/src/client/cl_sound.cpp

.include <bsd.port.post.mk>
