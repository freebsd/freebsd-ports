#
# Ports collection makefile for:	scorched3d
# Date created:				Jan 5, 2003
# Whom:					mdodd
#
# $FreeBSD$

PORTNAME=		scorched3d
PORTVERSION=		0.${SCORCH_VERSION}${SCORCH_REVISION}
PORTREVISION=	1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	scorched3d
DISTNAME=		Scorched3D-${SCORCH_VERSION}-src

MAINTAINER=		guy@device.dyndns.org
COMMENT=		Scorched is a game based loosely on the classic DOS game

BUILD_DEPENDS=		${X11BASE}/include/wx-2.6/wx/wx.h:${PORTSDIR}/x11-toolkits/wxgtk26-common \
			wxgtk2-2.6-config:${PORTSDIR}/x11-toolkits/wxgtk26 \
			openal-config:${PORTSDIR}/audio/openal
RUN_DEPENDS=		${X11BASE}/include/wx-2.6/wx/wx.h:${PORTSDIR}/x11-toolkits/wxgtk26-common \
			wxgtk2-2.6-config:${PORTSDIR}/x11-toolkits/wxgtk26 \
			openal-config:${PORTSDIR}/audio/openal
LIB_DEPENDS=		alut.0:${PORTSDIR}/audio/freealut

SCORCH_VERSION=		39.1

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
.endif
USE_SDL=		mixer net sdl
GNU_CONFIGURE=		yes
USE_GL=			yes
USE_GMAKE=		yes
USE_AUTOTOOLS=	automake:15 autoconf:253

WRKSRC=			${WRKDIR}/scorched
AUTOMAKE_ARGS=		--foreign
CONFIGURE_ARGS=		--program-prefix='' \
			--prefix=${PREFIX}/games/scorched3d \
			--datadir=${PREFIX}/games/scorched3d \
			--with-wx-config=${X11BASE}/bin/wxgtk2-2.6-config
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
.endif
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=		ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" \
			AUTOMAKE="${TRUE}" AUTOHEADER="${TRUE}"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E 's,#include.*<SDL/(SDL.*\.h)>,#include <SDL11/\1>,g' \
		${WRKSRC}/configure.ac \
		${WRKSRC}/src/GLEXT/GLBitmap.cpp \
		${WRKSRC}/src/GLEXT/GLState.h \
		${WRKSRC}/src/GLEXT/GLStateExtension.cpp \
		${WRKSRC}/src/client/ClientMain.cpp \
		${WRKSRC}/src/client/SoftwareMouse.cpp \
		${WRKSRC}/src/client/UniqueIdStore.cpp \
		${WRKSRC}/src/common/Clock.cpp \
		${WRKSRC}/src/common/Display.h \
		${WRKSRC}/src/common/Gamma.cpp \
		${WRKSRC}/src/common/Gamma.h \
		${WRKSRC}/src/common/KeyStateTranslate.h \
		${WRKSRC}/src/common/KeyTranslate.h \
		${WRKSRC}/src/common/KeyboardHistory.h \
		${WRKSRC}/src/common/Logger.cpp \
		${WRKSRC}/src/common/Mouse.h \
		${WRKSRC}/src/common/RandomGenerator.cpp \
		${WRKSRC}/src/coms/NetBuffer.cpp \
		${WRKSRC}/src/coms/NetBuffer.h \
		${WRKSRC}/src/coms/NetMessageHandler.h \
		${WRKSRC}/src/coms/NetMessagePool.h \
		${WRKSRC}/src/engine/MainLoop.cpp \
		${WRKSRC}/src/scorched/MainDialog.cpp \
		${WRKSRC}/src/scorched/main.cpp \
		${WRKSRC}/src/server/ServerBrowserInfo.h \
		${WRKSRC}/src/server/ServerMain.cpp
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,g' \
		${WRKSRC}/src/3dsparse/aseFile.tab.cpp \
		${WRKSRC}/src/ode/config.h
	

pre-configure:
	@cd ${WRKSRC}/scripts && ${PERL} createAMMakefile.pl
	@cd ${WRKSRC} && ${ACLOCAL}

pre-install:
	@${MKDIR} ${PREFIX}/games/scorched3d

.include <bsd.port.post.mk>
