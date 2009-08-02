# New ports collection makefile for:	clanlib
# Date created:				10 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $Carpetsmoker: ports/devel/clanlib/Makefile,v 1.3 2008/03/18 13:48:24 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	clanlib
PORTVERSION=	0.8.1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.clanlib.org/download/releases-0.8/
DISTNAME=	ClanLib-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform game SDK

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mikmod:${PORTSDIR}/audio/libmikmod \
		vorbis:${PORTSDIR}/audio/libvorbis

WRKSRC=		${WRKDIR}/ClanLib-${PORTVERSION}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-clanJavaScript --disable-docs
USE_GMAKE=	yes
USE_XORG=	x11 xmu xi
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
USE_SDL=	gfx
USE_GL=		yes

.include <bsd.port.pre.mk>

# Is this still true for 0.8? Removed until we've got some
# confirmation on this.
#.if ${ARCH} != "i386" && ${ARCH} != "amd64"
#BROKEN=		"Does not compile on !i386 and !amd64"
#.endif

post-patch:
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|(CLvoid)|()|' \
		${WRKSRC}/Sources/API/GL/opengl_wrap.h
	@${REINPLACE_CMD} -e 's|-lasound||' \
		${WRKSRC}/Sources/Sound/Makefile.in
	@${REINPLACE_CMD} -e 's|@perl_exec@|${PERL}|g' \
		${WRKSRC}/Documentation/Utilities/webbuilder.pl.in

.include <bsd.port.post.mk>
