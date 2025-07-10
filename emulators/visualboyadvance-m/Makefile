PORTNAME=	visualboyadvance-m
PORTVERSION=	2.0.0b2
PORTREVISION=	12
CATEGORIES=	emulators

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game Boy Advance emulator with GTK frontend
WWW=		https://vba-m.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/gpl.txt

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake:insource,noninja dos2unix gl gnome \
		pkgconfig sdl xorg
DOS2UNIX_REGEX=	.*\.(c|cpp|h|ypp)
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_TAGNAME=	VBA-M_Beta_2
USE_GL=		gl glu
USE_SDL=	sdl
USE_XORG=	x11 xext

CMAKE_ARGS=	-DVERSION:STRING="${PORTVERSION}" \
		-DSYSCONFDIR:STRING="${PREFIX}/etc"  \
		-DENABLE_WX:BOOL=no

OPTIONS_DEFINE=	NLS FFMPEG LINK LIRC DEBUGGER
OPTIONS_DEFINE_i386=	ASMCORE	ASMSCALERS
OPTIONS_DEFAULT=	DEBUGGER SDL
OPTIONS_MULTI=	INTERFACE
OPTIONS_MULTI_INTERFACE=	GVBAM SDL
OPTIONS_SUB=	yes

ASMCORE_DESC=	Enable x86 ASM CPU cores (i386 only)
ASMSCALERS_DESC=	Enable x86 ASM graphic filters (i386 only)
DEBUGGER_DESC=	Enable the debugger
FFMPEG_DESC=	Enable FFmpeg A/V recording
GVBAM_DESC=	Enable GTK interface
LINK_DESC=	Enable GBA linking functionality
LIRC_DESC=	Enable LIRC infrared support
SDL_DESC=	Enable SDL interface

ASMCORE_BUILD_DEPENDS=	as:devel/binutils
ASMCORE_CMAKE_BOOL=	ENABLE_ASM_CORE
ASMSCALERS_BUILD_DEPENDS=	nasm:devel/nasm
ASMSCALERS_CMAKE_BOOL=		ENABLE_ASM_SCALERS
DEBUGGER_CMAKE_BOOL=	ENABLE_DEBUGGER
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	ENABLE_FFMPEG
GVBAM_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libgdkglext-x11-1.0.so:x11-toolkits/gtkglext \
			libgdkglextmm-x11-1.2.so:x11-toolkits/gtkglextmm
GVBAM_USES=		desktop-file-utils
GVBAM_USE=		GNOME=gtkmm24,pangox-compat
GVBAM_CMAKE_BOOL=	ENABLE_GTK
LINK_LIB_DEPENDS=	libsfml-system.so:devel/sfml
LINK_CMAKE_BOOL=	ENABLE_LINK
LINK_BROKEN=		Does not build
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_RUN_DEPENDS=	lircd:comms/lirc
LIRC_CMAKE_BOOL=	ENABLE_LIRC
NLS_USES=		gettext
NLS_CMAKE_BOOL=		ENABLE_NLS
SDL_IMPLIES=		DEBUGGER
SDL_CMAKE_BOOL=		ENABLE_SDL

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

post-patch:
	@${REINPLACE_CMD} -e '/SET.*LIRC_CLIENT_LIBRARY/ s|lirc_client|${LOCALBASE}/lib/lib&.so|' \
		${WRKSRC}/CMakeLists.txt

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
