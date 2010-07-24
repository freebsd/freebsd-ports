# New ports collection makefile for:	lightspark
# Date created:		18 May 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lightspark
DISTVERSION=	r20100625
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An alternative Flash Player implementation

BUILD_DEPENDS=	${LOCALBASE}/include/llvm/Support/DataFlow.h:${PORTSDIR}/devel/llvm \
		nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS=	${LOCALBASE}/include/llvm/Support/DataFlow.h:${PORTSDIR}/devel/llvm \
		${LOCALBASE}/lib/X11/fonts/Liberation/LiberationSerif-Regular.ttf:${PORTSDIR}/x11-fonts/liberation-fonts-ttf
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		pcrecpp.0:${PORTSDIR}/devel/pcre \
		ftgl.2:${PORTSDIR}/graphics/ftgl \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Uses assembly code

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_EXE_LINKER_FLAGS="-L${LOCALBASE}/lib" \
		-DCMAKE_SHARED_LINKER_FLAGS="-L${LOCALBASE}/lib"
USE_SDL=	sdl
USE_GL=		gl glew
MAKE_JOBS_SAFE=	yes
USE_PERL5_BUILD=yes # for llvm-config; see ports/146711
USE_LDCONFIG=	yes

CXXFLAGS+=	-fpermissive

PORTDOCS=	*

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	PLUGIN	"Enable browser plugin" off \
		SOUND	"Enable sound (requires libpulse)" on

.include <bsd.port.options.mk>

.if ${OSVERSION} < 700042
BROKEN=		Does not compile on 6.x
.endif

.if defined(WITH_PLUGIN)
USE_GNOME+=	gtk20
LIB_DEPENDS+=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=liblightsparkplugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
CXXFLAGS+=	-I${LOCALBASE}/include/firefox3
BUILD_DEPENDS+=	${LOCALBASE}/include/firefox3/npfunctions.h:${PORTSDIR}/www/firefox \
		${LOCALBASE}/libdata/pkgconfig/mozilla-plugin.pc:${PORTSDIR}/www/libxul
RUN_DEPENDS+=	${LOCALBASE}/include/firefox3/npfunctions.h:${PORTSDIR}/www/firefox \
		${LOCALBASE}/libdata/pkgconfig/mozilla-plugin.pc:${PORTSDIR}/www/libxul
PLIST_SUB+=	PLUGIN=""
CMAKE_ARGS+=	-DCOMPILE_PLUGIN:BOOL=ON \
		-DPLUGIN_DIRECTORY:STRING="${WEBPLUGINS_DIR}"
.else
PLIST_SUB+=	PLUGIN="@comment "
CMAKE_ARGS+=	-DCOMPILE_PLUGIN:BOOL=OFF
.endif

.if defined(WITH_SOUND)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-DENABLE_SOUND:BOOL=OFF
.endif

.if defined(WITH_PLUGIN)
pre-everything::
	@${ECHO_CMD} "Lightspark is currently in pre-alpha state, so only use its plugin"
	@${ECHO_CMD} "if you know what you are doing; otherwise, expect browser crashes and hangs"
	@${ECHO_CMD} "Also, you'll probably need to edit kernel source and bump SEM_MAX from 30"
	@${ECHO_CMD} "to something much higher (1024 or so) to make the plugin work..."
	@sleep 3
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
