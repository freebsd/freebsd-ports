# New ports collection makefile for:	clanlib
# Date created:				10 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clanlib
PORTVERSION=	0.7.8.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel
DISTNAME=	ClanLib-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Cross-platform game SDK

LIB_DEPENDS=	Hermes.1:${PORTSDIR}/graphics/Hermes \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

# conflicts with devel/clanlib
CONFLICTS=	clanlib-0.6.*

WRKSRC=		${WRKDIR}/ClanLib-${PORTVERSION:R}

LATEST_LINK=	clanlib-devel
USE_BZIP2=	yes
USE_PERL5_BUILD=	yes
USE_XLIB=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-clanJavaScript --disable-docs
INSTALLS_SHLIB=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PLIST_SUB=	VER=${PORTVERSION:C/(^[0-9]\.[0-9]).*/\1/}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		"Does not compile on !i386 and !amd64"
.endif

.if ${OSVERSION} < 500032
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CPPFLAGS+=	-I${LOCALBASE}/include/stlport
LDFLAGS+=	-lstlport_gcc
CFLAGS+=	-O0
.endif

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-clanSDL
PLIST_SUB+=	SDL="@comment "
.else
USE_SDL=	sdl
CONFIGURE_ARGS+=	--disable-sdltest
PLIST_SUB+=	SDL=""
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=	--disable-clanGL
PLIST_SUB+=	OPENGL="@comment "
.else
USE_GL=	yes
PLIST_SUB+=	OPENGL=""
.endif

.if defined(WITHOUT_MIKMOD)
CONFIGURE_ARGS+=	--disable-clanMikMod
PLIST_SUB+=	LIBMIKMOD="@comment "
.else
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
PLIST_SUB+=	LIBMIKMOD=""
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--disable-clanVorbis
PLIST_SUB+=	LIBVORBIS="@comment "
.else
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	LIBVORBIS=""
.endif

pre-everything::
	@${ECHO_MSG} "ClanLib has the following tunables option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_SDL=yes		Turns off SDL support"
	@${ECHO_MSG} "	WITHOUT_OPENGL=yes	Turns off OpenGL support"
	@${ECHO_MSG} "	WITHOUT_MIKMOD=yes	Turns off libmikmod support"
	@${ECHO_MSG} "	WITHOUT_VORBIS=yes	Turns off libvorbis support"
	@${ECHO_MSG} ""

post-patch:
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|-lpthread||g' \
		${WRKSRC}/Sources/Core/Makefile.in
	@${REINPLACE_CMD} -e 's|@perl_exec@|${PERL}|g' \
		${WRKSRC}/Documentation/Utilities/webbuilder.pl.in

.include <bsd.port.post.mk>
