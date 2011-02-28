# New ports collection makefile for:	clutter
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#  $MCom: ports/graphics/clutter/Makefile,v 1.34 2010/09/24 16:35:42 kwm Exp $
#

PORTNAME=	clutter
PORTVERSION=	1.4.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME \
		http://source.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LIB_DEPENDS=	json-glib-1.0.0:${PORTSDIR}/devel/json-glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	pkgconfig gdkpixbuf2 gnomehack ltverhack gnomeprefix atk pango
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
