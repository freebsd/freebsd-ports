# New ports collection makefile for:	blender
# Date created:				27 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	blender
PORTVERSION=	2.27
CATEGORIES=	graphics games
MASTER_SITES=	http://download.blender.org/source/
PKGNAMESUFFIX=	-devel

MAINTAINER=	dyeske@yahoo.com
COMMENT=	3D modeling/rendering/animation/gaming package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		nspr4.1:${PORTSDIR}/devel/nspr \
		openal.0:${PORTSDIR}/audio/openal \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
PYTHON_VERSION=	python2.2
USE_MESA=	yes

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

PLUGIN_DIR?=	lib/mozilla/plugins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|g' \
		${WRKSRC}/extern/ode/dist/configurator.c \
		${WRKSRC}/source/gameengine/SoundSystem/intern/SND_WaveCache.cpp
	@${REINPLACE_CMD} -E -e \
		's|-Wall||; \
		s|g\+\+|${CXX}|; \
		s|LEVEL_2_C_WARNINGS.+$$||; \
		s|LEVEL_2_CPP_WARNINGS.+$$||; \
		s|-FIX_NAN_WARN||' \
		${WRKSRC}/source/nan_warn.mk
	@${REINPLACE_CMD} -e \
		's|gcc|${CC}|; \
		s|\$$(C_OPT)1|${CFLAGS}|; \
		s|\$$(C_OPT)\$$(OPT)|${CFLAGS}|' \
		${WRKSRC}/extern/ode/dist/Makefile
	@${REINPLACE_CMD} -E -e \
		's|g\+\+|${CXX}|; \
		s,(-O2|-DNDEBUG|^DBG_C.+$$),,; \
		s|-pipe|${CFLAGS}|; \
		s|gcc|${CC}|' \
		${WRKSRC}/source/nan_compile.mk
	@${REINPLACE_CMD} -e \
		's|-pthread -lc_r|${PTHREAD_LIBS}|' \
		${WRKSRC}/source/nan_link.mk
	@${REINPLACE_CMD} -e \
		's|%%CFLAGS%%|${CFLAGS}|' \
		${WRKSRC}/intern/python/freeze/freeze.py
	@${REINPLACE_CMD} -E -e \
		's|-Wall||g; \
		s|^CC.+$$|CC=${CC}|; \
		s|g\+\+|${CXX}|; \
		s|-L/usr/lib/X11R6||; \
		s|-L/usr/lib/X11|-lXext|; \
		s|-ffast-math|-I${X11BASE}/include|' \
		${WRKSRC}/extern/ode/dist/config/makefile.unix-gcc
	@${REINPLACE_CMD} -e \
		's|\$$(NAN_LIBDIR)/\$$(CONFIG_GUESS)|\$$(NAN_LIBDIR)|; \
		s|\$$(NAN_OBJDIR)/\$$(CONFIG_GUESS)|\$$(NAN_OBJDIR)|' \
		${WRKSRC}/source/nan_definitions.mk
	@${REINPLACE_CMD} -e \
		's,/usr/local,${LOCALBASE},g; \
		s,/usr/X11R6,${X11BASE},g' \
		${WRKSRC}/source/*.mk

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/bin/blender ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/bin/blenderplayer \
		${PREFIX}/bin
	@${MKDIR} ${PREFIX}/${PLUGIN_DIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/obj/npBlender3DPlugin.so \
		${PREFIX}/${PLUGIN_DIR}

.include <bsd.port.mk>
