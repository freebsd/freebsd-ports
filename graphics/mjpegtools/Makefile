# New ports collection makefile for:	mjpegtools
# Date created:		Wed May 29 21:12:38 UTC 2002
# Whom:	          Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mjpegtools
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mjpeg

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	aviplay-0.7.0:${PORTSDIR}/graphics/avifile \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GLIB=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
WANT_GTK=	yes

MAN1=   divxdec.1 jpeg2yuv.1 lav2divx.1 lav2mpeg.1 lav2wav.1 lav2yuv.1 \
	lavpipe.1 lavplay.1 lavrec.1 lavtrans.1 mjpegtools.1 mp2enc.1 \
	mpeg2enc.1 mplex.1 ppmtoy4m.1 y4mcolorbars.1 y4mtoppm.1 \
	yuv2divx.1 yuv2lav.1 yuvdenoise.1 yuvkineco.1 yuvmedianfilter.1 \
	yuvplay.1 yuvscaler.1 yuvycsnoise.1
MAN5=	yuv4mpeg.5

SDL_CONFIG?=		${LOCALBASE}/bin/sdl11-config

DOC_FILES=	AUTHORS BUGS CHANGES COPYING ChangeLog HINTS NEWS \
		PLANS README README.DV README.avilib README.glav \
		README.lavpipe README.transist TODO

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
PLIST_SUB+=	DIVX='@comment '
.else
PLIST_SUB+=	DIVX=''
.endif

# pre-detection
# LIBDV
.if exists(${LOCALBASE}/lib/libdv.so.1)
WITH_LIBDV=	yes
.endif
# LIBMOVTAR
.if exists(${LOCALBASE}/lib/libmovtar.a)
WITH_LIBMOVTAR=	yes
.endif
# QUICKTIME
.if exists(${LOCALBASE}/lib/libopenquicktime.so.0)
WITH_QUICKTIME=	yes
.endif
# SDL
.if exists(${LOCALBASE}/lib/libSDL-1.1.so.4)
WITH_SDL=	yes
.endif

# option activation
.ifdef(HAVE_GTK)
USE_GTK=	yes
.endif
#
.ifdef(WITH_LIBDV)
LIB_DEPENDS+=	dv.1:${PORTSDIR}/graphics/libdv

CONFIGURE_ARGS+=	--with-dv=${LOCALBASE}
.endif
#
.ifdef(WITH_LIBMOVTAR)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmovtar.a:${PORTSDIR}/graphics/libmovtar

CONFIGURE_ARGS+=	--with-movtar-prefix=${LOCALBASE}
.endif
#
.ifdef(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

CONFIGURE_ARGS+=	--with-sdl
CONFIGURE_ENV+=		SDL_CONFIG="${SDL_CONFIG}"
.endif
#
.ifdef(WITH_QUICKTIME)
LIB_DEPENDS+=	openquicktime.0:${PORTSDIR}/graphics/openquicktime

CONFIGURE_ARGS+=	--with-quicktime=${LOCALBASE}
.endif

pre-everything::
.ifndef(HAVE_GTK)
	@${ECHO_MSG} "====> You can enable GTK support by defining WITH_GTK"
.endif
.ifndef(WITH_LIBDV)
	@${ECHO_MSG} "====> You can enable DV support by defining WITH_LIBDV"
.endif
.ifndef(WITH_LIBMOVTAR)
	@${ECHO_MSG} "====> You can enable movtar support by defining WITH_LIBMOVTAR"
.endif
.ifndef(WITH_QUICKTIME)
	@${ECHO_MSG} "====> You can enable quicktime support by defining WITH_QUICKTIME"
.endif
.ifndef(WITH_SDL)
	@${ECHO_MSG} "====> You can enable SDL support by defining WITH_SDL"
.endif

post-patch:
	@${PERL} -pi -e 's|^(pkgconfigdir = )\$$\(libdir\)/(pkgconfig)|\1${PREFIX}/libdata/\2|' \
		${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's|stdint.h|sys/types.h|' \
		${WRKSRC}/lavtools/lav2divx.cpp \
		${WRKSRC}/lavtools/yuv2divx.cpp \
		${WRKSRC}/lavtools/divxdec.cpp
	@${PERL} -pi -e 's@(-l(jpeg|openquicktime|png))@-L${LOCALBASE}/lib \1@; \
		s|(-I) (\$$with_quicktime)|\1\2/include/openquicktime|; \
		s|(with_quicktime/)(openquicktime)(.h)|\1include/\2/\2\3|; \
		s|-ldl||; \
		s|(-ldv)|-L${LOCALBASE}/lib \1 ${PTHREAD_LIBS:S/"//g}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${PERL} -pi -e 's|SDL/|SDL11/|' \
		${WRKSRC}/lavtools/liblavplay.c \
		${WRKSRC}/lavtools/yuvplay.c
.ifdef(WITH_QUICKTIME)
	@${PERL} -pi -e 's|^(have_openquicktime=).+|\1true|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${PERL} -pi -e 's|HAVE_OPENQUICKTIME|__FreeBSD__|' \
		${WRKSRC}/lavtools/lav_io.h
.endif

pre-build:
.ifdef(WITH_QUICKTIME)
	@${ECHO_CMD} "#define HAVE_OPENQUICKTIME 1" >> ${WRKSRC}/config.h
.endif

.include <bsd.port.post.mk>
