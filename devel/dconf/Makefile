# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dconf
PORTVERSION=	0.36.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DISTNAME=	dconf-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Configuration database system for GNOME

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala>=0.18.1:lang/vala \
		docbook-xsl>=0:textproc/docbook-xsl \
		${LOCALBASE}/libdata/pkgconfig/bash-completion.pc:shells/bash-completion
LIB_DEPENDS=	libdbus-1.so:devel/dbus

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:3.6+,build tar:xz
USE_GNOME=	glib20 libxslt:build
USE_LDCONFIG=	yes
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Dman=true \
		-Dgtk_doc=false \
		-Dvapi=true

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dconf/db
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dconf/profile

.include <bsd.port.mk>
