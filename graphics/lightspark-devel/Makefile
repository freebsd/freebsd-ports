# New ports collection makefile for:	lightspark
# Date created:		18 May 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lightspark
DISTVERSION=	r20100518
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
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_SDL=	sdl
USE_GL=		gl glew
MAKE_JOBS_SAFE=	yes
USE_PERL5_BUILD=yes # for llvm-config; see ports/146711

CXXFLAGS+=	-fpermissive

PORTDOCS=	*

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	PLUGIN     "Enable browser plugin" off

.include <bsd.port.options.mk>

.if ${OSVERSION} < 700042
BROKEN=		Does not compile on 6.x
.endif

.if defined(WITH_PLUGIN)
CMAKE_ARGS+=	-DCOMPILE_PLUGIN:BOOL=ON
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
.else
CMAKE_ARGS+=	-DCOMPILE_PLUGIN:BOOL=OFF
PLIST_SUB+=	PLUGIN="@comment "
.endif

.if defined(WITH_PLUGIN)
pre-everything::
	@${ECHO_CMD} "Lightspark is currently in pre-alpha state, so only use its plugin"
	@${ECHO_CMD} "if you know what you are doing; otherwise, expect browser crashes and hangs"
	@sleep 3
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|x86_64|amd64|' ${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/plugin-dir/CMakeLists.txt
	@${TOUCH} ${WRKSRC}/conf/CMakeDetermineASM-NASMCompiler.cmake
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr.*/LiberationSerif-Regular.ttf|${LOCALBASE}/lib/X11/fonts/Liberation/LiberationSerif-Regular.ttf|' \
		${WRKSRC}/swf.cpp
.if defined(WITH_PLUGIN)
	@${REINPLACE_CMD} -e 's|/usr/lib/mozilla/plugins|${WEBPLUGINS_DIR}|' \
		${WRKSRC}/plugin-dir/CMakeLists.txt
.endif

post-install:
	${CHMOD} a+x ${PREFIX}/bin/lightspark
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
