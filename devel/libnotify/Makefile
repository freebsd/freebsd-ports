# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	libnotify
PORTVERSION=	0.7.8
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for desktop notifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome libtool meson pkgconfig tar:xz
USE_GNOME=	glib20 gdkpixbuf2 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dtests=false -Ddocbook_docs=disabled -Dgtk_doc=false

.include <bsd.port.mk>
