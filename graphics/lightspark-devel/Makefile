# New ports collection makefile for:	lightspark
# Date created:		18 May 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lightspark
DISTVERSION=	r20110309
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An alternative Flash Player implementation

BUILD_DEPENDS=	${LOCALBASE}/include/llvm/Support/DataFlow.h:${PORTSDIR}/devel/llvm \
		nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS=	${LOCALBASE}/include/llvm/Support/DataFlow.h:${PORTSDIR}/devel/llvm \
		${LOCALBASE}/lib/X11/fonts/Liberation/LiberationSerif-Regular.ttf:${PORTSDIR}/x11-fonts/liberation-fonts-ttf
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		pcrecpp.0:${PORTSDIR}/devel/pcre \
		ftgl.2:${PORTSDIR}/graphics/ftgl \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		boost_system:${PORTSDIR}/devel/boost-libs \
		rtmp.0:${PORTSDIR}/multimedia/rtmpdump \
		xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26 \
		pulse.0:${PORTSDIR}/audio/pulseaudio

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
USE_GETTEXT=	yes
USE_GCC=	4.4+

PORTDOCS=	*

MAN1=		lightspark.1

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	PLUGIN	"Enable browser plugin" off

.include <bsd.port.options.mk>

.if defined(WITH_PLUGIN)
USE_GNOME+=	gtk20
LIB_DEPENDS+=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=liblightsparkplugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
CXXFLAGS+=	-I${LOCALBASE}/include/firefox3
USE_FIREFOX_BUILD=	36
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/mozilla-plugin.pc:${PORTSDIR}/www/libxul
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/mozilla-plugin.pc:${PORTSDIR}/www/libxul
PLIST_SUB+=	PLUGIN=""
CMAKE_ARGS+=	-DCOMPILE_PLUGIN:BOOL=ON \
		-DPLUGIN_DIRECTORY:STRING="${WEBPLUGINS_DIR}"
.else
PLIST_SUB+=	PLUGIN="@comment "
CMAKE_ARGS+=	-DCOMPILE_PLUGIN:BOOL=OFF
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
