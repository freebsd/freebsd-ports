# New ports collection makefile for:	libdv
# Date created:				Sun Nov 18 19:42:02 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdv
PORTVERSION=	0.9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		popt.0:${PORTSDIR}/devel/popt \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12

USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include `${GTK_CONFIG} --cflags` \
		`${GDK_PIXBUF_CONFIG} --cflags`" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib \
		`${GTK_CONFIG} --libs` `${GDK_PIXBUF_CONFIG} --libs`"
CONFIGURE_ARGS=	--with-sdl-prefix="${LOCALBASE}"
INSTALLS_SHLIB=	yes

MAN1=	encodedv.1 playdv.1

GDK_PIXBUF_CONFIG?=${X11BASE}/bin/gdk-pixbuf-config

post-configure:
	@find ${WRKSRC} -type f -name Makefile -exec \
		${PERL} -pi.orig -ne 's!-l(gdk|glib|gtk) !!g' {} \;

post-install:
.ifndef(NOPORTDOCS)
.endif

.include <bsd.port.mk>
