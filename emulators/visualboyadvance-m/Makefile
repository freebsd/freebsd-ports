# Created by: Nicole Reid <root@cooltrainer.org>

PORTNAME=	visualboyadvance-m
PORTVERSION=	2.0.0b2
PORTREVISION=	11
CATEGORIES=	emulators

MAINTAINER=	root@cooltrainer.org
COMMENT=	Game Boy Advance emulator with GTK frontend

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/gpl.txt

BROKEN_aarch64=		fails to build: regparm is not valid on this platform
BROKEN_armv6=		fails to build: regparm is not valid on this platform
BROKEN_armv7=		fails to build: regparm is not valid on this platform

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake:insource,noninja compiler:c++11-lang dos2unix gl gnome \
		pkgconfig sdl xorg
DOS2UNIX_REGEX=	.*\.(c|cpp|h|ypp)
USE_XORG=	x11 xext
USE_GL=		gl glu
USE_SDL=	sdl
INSTALLS_ICONS=	yes
CMAKE_ARGS=	-DVERSION:STRING="${PORTVERSION}" \
		-DSYSCONFDIR:STRING="${PREFIX}/etc"  \
		-DENABLE_WX:BOOL=no

USE_GITHUB=	yes
GH_TAGNAME=	VBA-M_Beta_2

OPTIONS_DEFINE=	NLS FFMPEG LINK LIRC DEBUGGER
OPTIONS_MULTI=	INTERFACE
OPTIONS_MULTI_INTERFACE=	GVBAM SDL
OPTIONS_DEFINE_i386=	ASMCORE	ASMSCALERS
OPTIONS_DEFAULT=	DEBUGGER SDL
OPTIONS_SUB=	yes

GVBAM_DESC=	Enable GTK interface
SDL_DESC=	Enable SDL interface
FFMPEG_DESC=	Enable FFmpeg A/V recording
LINK_DESC=	Enable GBA linking functionality
LIRC_DESC=	Enable LIRC infrared support
DEBUGGER_DESC=	Enable the debugger
ASMCORE_DESC=	Enable x86 ASM CPU cores (i386 only)
ASMSCALERS_DESC=	Enable x86 ASM graphic filters (i386 only)

ASMCORE_BUILD_DEPENDS=	as:devel/binutils
ASMCORE_CMAKE_BOOL=	ENABLE_ASM_CORE

ASMSCALERS_BUILD_DEPENDS=	nasm:devel/nasm
ASMSCALERS_CMAKE_BOOL=		ENABLE_ASM_SCALERS

GVBAM_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libgdkglext-x11-1.0.so:x11-toolkits/gtkglext \
			libgdkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm
GVBAM_USES=		desktop-file-utils
GVBAM_USE=		GNOME=gtkmm24,pangox-compat
GVBAM_CMAKE_BOOL=	ENABLE_GTK

SDL_IMPLIES=		DEBUGGER
SDL_CMAKE_BOOL=		ENABLE_SDL

DEBUGGER_CMAKE_BOOL=	ENABLE_DEBUGGER

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	ENABLE_FFMPEG

NLS_USES=		gettext
NLS_CMAKE_BOOL=		ENABLE_NLS

LINK_CMAKE_BOOL=	ENABLE_LINK
LINK_LIB_DEPENDS=	libsfml-system.so:devel/sfml

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_RUN_DEPENDS=	lircd:comms/lirc
LIRC_CMAKE_BOOL=	ENABLE_LIRC

post-patch:
	@${REINPLACE_CMD} -e '/SET.*LIRC_CLIENT_LIBRARY/ s|lirc_client|${LOCALBASE}/lib/lib&.so|; \
		s|share/man|man|' ${WRKSRC}/CMakeLists.txt

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export -r${SVN_REV} \
		 https://svn.code.sf.net/p/vbam/code/trunk/ ${DISTNAME}
	${TAR} jcf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}
	${RM} -r ${DISTNAME}

post-install-SDL-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vbam

post-install-GVBAM-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gvbam

.include <bsd.port.mk>
