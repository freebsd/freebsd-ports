# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gx
PORTVERSION=	0.4.0
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://BSDforge.com/projects/source/graphics/gx/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lightweight image viewer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnomevfsmm-2.6.so:devel/gnome-vfsmm

USES=		compiler:c++11-lang desktop-file-utils gettext pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	gconfmm26 gtkmm24
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gx \
		share/applications/gx.desktop \
		share/pixmaps/gx.png \
		share/pixmaps/gx_logo.png \

.include <bsd.port.mk>
