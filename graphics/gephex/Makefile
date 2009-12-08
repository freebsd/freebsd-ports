# New ports collection makefile for: gephex
# Date created:		25 Jan 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	gephex
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.gephex.org/download/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software-based interactive video-effect system

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

BROKEN=		does not build
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

OPTIONS=	SDL	"Turn on SDL support"		on \
		AALIB	"Turn on AALIB support"		on \
		FFMPEG	"Turn on FFMPEG support"	on \
		MPEG3	"Turn on MPEG3 support"		off \
		PNG	"Turn on PNG support"		off \
		GL	"Turn on GL support"		off

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build uic_build
USE_XORG=	xv
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:18 autoconf:262 libtool:22
AUTOMAKE_ARGS=	--foreign
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--without-ASOUNDLIB --without-AVIFILE \
		--without-LINUX_JOYSTICK --without-V4L \
		--disable-static

MAN1=		gephex-engine.1 gephex-gui.1 gephex.1

PLIST_SUB=	VERSION="${PORTVERSION:R}"
PORTREVISION=	1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-mmx
.else
BUILD_DEPENDS+=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm
.endif

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--without-SDL --without-SDL_IMAGE --without-SDL_TTF
PLIST_SUB+=	SDL="@comment "
.else
CONFIGURE_ARGS+=	--with-SDL --with-SDL_IMAGE --with-SDL_TTF
USE_SDL=	sdl image ttf
PLIST_SUB+=	SDL=""
.endif

.if defined(WITHOUT_AALIB)
CONFIGURE_ARGS+=	--without-AALIB
PLIST_SUB+=	AALIB="@comment "
.else
CONFIGURE_ARGS+=	--with-AALIB
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	AALIB=""
.endif

.if defined(WITHOUT_FFMPEG)
CONFIGURE_ARGS+=	--without-FFMPEG
PLIST_SUB+=	FFMPEG="@comment "
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libavcodec.a:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--with-FFMPEG
PLIST_SUB+=	FFMPEG=""
.endif

.if defined(WITH_MPEG3)
CONFIGURE_ARGS+=	--with-MPEG3
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmpeg3.a:${PORTSDIR}/multimedia/libmpeg3
PLIST_SUB+=	MPEG3=""
.else
CONFIGURE_ARGS+=	--without-MPEG3
PLIST_SUB+=	MPEG3="@comment "
.endif

.if defined(WITH_PNG)
CONFIGURE_ARGS+=	--with-LIBPNG
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=	--without-LIBPNG
PLIST_SUB+=	PNG="@comment "
.endif

.if defined(WITH_GL)
CONFIGURE_ARGS+=	--with-GL
USE_GL=		gl
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=	--without-GL
PLIST_SUB+=	GL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$QTDIR/include |${QT_INCDIR} |g ; \
		 s|$$QTDIR/lib |${QT_LIBDIR} |g ; \
		 s|$$QTDIR/bin |${QT_PREFIX}/bin |g ; \
		 s|/moc|/${MOC:T}|g ; \
		 s|/uic|/${UIC:T}|g' ${WRKSRC}/acinclude.m4
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure.ac

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
