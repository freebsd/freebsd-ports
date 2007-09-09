# New ports collection makefile for:	clanlib
# Date created:				10 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $Carpetsmoker: ports/devel/clanlib/Makefile,v 1.2 2007/07/22 00:53:05 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	clanlib
PORTVERSION=	0.8.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-0.8/ \
		http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/~tournoij/distfiles/
DISTNAME=	ClanLib-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	Cross-platform game SDK

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/ClanLib-${PORTVERSION}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-clanJavaScript --disable-docs
USE_GMAKE=	yes
USE_XLIB=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

# Is this still true for 0.8? Removed until we've got some
# confirmation on this.
#.if ${ARCH} != "i386" && ${ARCH} != "amd64"
#BROKEN=		"Does not compile on !i386 and !amd64"
#.endif

.if ${OSVERSION} < 500032
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CPPFLAGS+=	-I${LOCALBASE}/include/stlport
LDFLAGS+=	-lstlport_gcc
CFLAGS+=	-O0
.endif

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=--disable-clanSDL
PLIST_SUB+=	SDL="@comment "
.else
USE_SDL=	gfx
CONFIGURE_ARGS+=--disable-sdltest
PLIST_SUB+=	SDL=""
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=--disable-clanGL
PLIST_SUB+=	OPENGL="@comment "
.else
USE_GL=		yes
PLIST_SUB+=	OPENGL=""
.endif

.if defined(WITHOUT_MIKMOD)
CONFIGURE_ARGS+=--disable-clanMikMod
PLIST_SUB+=	LIBMIKMOD="@comment "
.else
LIB_DEPENDS+=	mikmod:${PORTSDIR}/audio/libmikmod
PLIST_SUB+=	LIBMIKMOD=""
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-clanVorbis
PLIST_SUB+=	LIBVORBIS="@comment "
.else
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	LIBVORBIS=""
.endif

pre-everything::
	@${ECHO_MSG} "ClanLib has the following tunables options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_SDL=yes		Turns off SDL support"
	@${ECHO_MSG} "	WITHOUT_OPENGL=yes	Turns off OpenGL support"
	@${ECHO_MSG} "	WITHOUT_MIKMOD=yes	Turns off libmikmod support"
	@${ECHO_MSG} "	WITHOUT_VORBIS=yes	Turns off libvorbis support"
	@${ECHO_MSG} ""

post-patch:
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|(CLvoid)|()|' \
		${WRKSRC}/Sources/API/GL/opengl_wrap.h
	@${REINPLACE_CMD} -e 's|@perl_exec@|${PERL}|g' \
		${WRKSRC}/Documentation/Utilities/webbuilder.pl.in

.include <bsd.port.post.mk>
