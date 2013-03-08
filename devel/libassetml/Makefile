# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libassetml
PORTVERSION=	1.2.1
PORTREVISION=	10
CATEGORIES=	devel gnome
MASTER_SITES=	SF/ofset/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Devel Library to share image and audio files between projects

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html
LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GNOME=	gnomehack lthack gnomeprefix glib20 libxml2
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

INFO=	libassetml

post-install:
	@${MKDIR} ${PREFIX}/share/assetml

.include <bsd.port.mk>
