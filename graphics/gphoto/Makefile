# New ports collection makefile for: 	gphoto
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gphoto
PORTVERSION=	0.4.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gphoto.org/projects/gphoto/pub/tar/stable/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gtktest --disable-imlibtest

MAN1=		gphoto.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gphoto
.for file in ChangeLog FAQ NEWS PROGRAMMERS README THANKS THEMES TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gphoto
.endfor
.endif

.include <bsd.port.mk>
