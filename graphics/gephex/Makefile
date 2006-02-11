# New ports collection makefile for: gephex
# Date created:		25 Jan 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	gephex
PORTVERSION=	0.4.3b
CATEGORIES=	graphics
MASTER_SITES=	http://www.gephex.org/download/src/

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Software-based interactive video-effect system

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_GMAKE=	yes
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
USE_AUTOTOOLS=	autoconf:259 autoheader:259 libtool:15 aclocal:19 automake:19
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--without-V4L --without-ASOUNDLIB --without-LINUX_JOYSTICK \
		--without-FFMPEG --without-AVIFILE --without-MPEG3 \
		--without-LIBPNG --without-SDL --without-SDL_IMAGE \
		--without-SDL_TTF --without-AALIB --disable-static
USE_QT_VER=	3
WANT_SDL=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/${PORTNAME}-${PORTVERSION:R}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[[:alpha:]]//g}

MAN1=		gephex-engine.1 gephex-gui.1 gephex.1

.include <bsd.port.pre.mk>

.if ${HAVE_SDL:Msdl} && ${HAVE_SDL:Mimage} && ${HAVE_SDL:Mttf} && !defined(WITHOUT_SDL)
WITH_SDL=	yes
.endif

.if exists(${LOCALBASE}/lib/libaa.so.1) && !defined(WITHOUT_AALIB)
WITH_AALIB=	yes
.endif

.if exists(${LOCALBASE}/bin/avifile-config) && !defined(WITHOUT_AVIFILE)
WITH_AVIFILE=	yes
.endif

.if exists(${LOCALBASE}/lib/libavcodec.a) && !defined(WITHOUT_FFMPEG)
WITH_FFMPEG=	yes
.endif

.if exists(${LOCALBASE}/lib/libmpeg3.a) && !defined(WITHOUT_MPEG3)
WITH_MPEG3=	yes
.endif

.if exists(${LOCALBASE}/lib/libpng.so.5) && !defined(WITHOUT_PNG)
WITH_PNG=	yes
.endif

.if exists(${X11BASE}/lib/libGL.so) && !defined(WITHOUT_GL)
WITH_GL=	yes
.endif

.if ${ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-mmx
.else
BUILD_DEPENDS+=		${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm
.endif

.ifdef (WITH_SDL)
CONFIGURE_ARGS+=	--with-SDL --with-SDL_IMAGE --with-SDL_TTF
USE_SDL=	sdl image ttf
.endif

.ifdef (WITH_AALIB)
CONFIGURE_ARGS+=	--with-AALIB
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
.endif

.ifdef (WITH_AVIFILE)
CONFIGURE_ARGS+=	--with-AVIFILE
LIB_DEPENDS+=	aviplay.0:${PORTSDIR}/multimedia/avifile
.endif

.ifdef (WITH_FFMPEG)
CONFIGURE_ARGS+=	--with-FFMPEG
BUILD_DEPENDS+=		${LOCALBASE}/lib/libavcodec.a:${PORTSDIR}/multimedia/ffmpeg
.endif

.ifdef (WITH_MPEG3)
CONFIGURE_ARGS+=	--with-MPEG3
BUILD_DEPENDS+=		${LOCALBASE}/lib/libmpeg3.a:${PORTSDIR}/multimedia/libmpeg3
.endif

.ifdef (WITH_PNG)
CONFIGURE_ARGS+=	--with-LIBPNG
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

.ifdef (WITH_GL)
CONFIGURE_ARGS+=	--with-GL
USE_GL=		yes
.endif

.if !defined(WITH_SDL)
PLIST_SUB+=	WITH_SDL="@comment "
.else
PLIST_SUB+=	WITH_SDL=""
.endif

.if !defined(WITH_FFMPEG)
PLIST_SUB+=	WITH_FFMPEG="@comment "
.else
PLIST_SUB+=	WITH_FFMPEG=""
.endif

.if !defined(WITH_PNG)
PLIST_SUB+=	WITH_PNG="@comment "
.else
PLIST_SUB+=	WITH_PNG=""
.endif

.ifdef (NOPORTDOCS)
DO_DOCS=\#
.endif

pre-everything::
	@${ECHO_CMD} "Building with the following configuration:"
.if defined (WITH_AALIB)
	@${ECHO_CMD} "WITH_AALIB=${WITH_AALIB}"
.else
	@${ECHO_CMD} "WITH_AALIB=no"
.endif
.if defined (WITH_AVIFILE)
	@${ECHO_CMD} "WITH_AVIFILE=${WITH_AVIFILE}"
.else
	@${ECHO_CMD} "WITH_AVIFILE=no"
.endif
.if defined (WITH_FFMPEG)
	@${ECHO_CMD} "WITH_FFMPEG=${WITH_FFMPEG}"
.else
	@${ECHO_CMD} "WITH_FFMPEG=no"
.endif
.if defined (WITH_GL)
	@${ECHO_CMD} "WITH_GL=${WITH_GL}"
.else
	@${ECHO_CMD} "WITH_GL=no"
.endif
.if defined (WITH_MPEG3)
	@${ECHO_CMD} "WITH_MPEG3=${WITH_MPEG3}"
.else
	@${ECHO_CMD} "WITH_MPEG3=no"
.endif
.if defined (WITH_PNG)
	@${ECHO_CMD} "WITH_PNG=${WITH_PNG}"
.else
	@${ECHO_CMD} "WITH_PNG=no"
.endif
.if defined (WITH_SDL)
	@${ECHO_CMD} "WITH_SDL=${WITH_SDL}"
.else
	@${ECHO_CMD} "WITH_SDL=no"
.endif
	@${ECHO_CMD} "Use WITH[OUT]_ definitions to change current port behaviour"

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|; \
			      s|%%X11BASE%%|${X11BASE}|; \
			      s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|%%PORTDOCS%%|${DO_DOCS}|' ${WRKSRC}/Makefile.am

# Compile contents of static libs with PIC, as they can be used in dynamic ones
.if !empty(ARCH:M*64)
	@(${FIND} -X ${WRKSRC} -name Makefile.am \! -regex '.*cpuinfo.*' | \
		${XARGS} ${REINPLACE_CMD} -E -e \
	"/^lib[[:alnum:]]+_a_SOURCES.*$$/{ h; s//AM_CFLAGS = -DPIC -fPIC/; G;}")
.endif

.include <bsd.port.post.mk>
