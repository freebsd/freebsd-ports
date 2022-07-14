# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	dconf
PORTVERSION=	0.40.0
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DISTNAME=	dconf-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Configuration database system for GNOME

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala>=0.18.1:lang/vala \
		docbook-xsl>=0:textproc/docbook-xsl \
		${LOCALBASE}/libdata/pkgconfig/bash-completion.pc:shells/bash-completion
LIB_DEPENDS=	libdbus-1.so:devel/dbus

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:3.6+,build tar:xz
USE_CSTD=	c99
USE_GNOME=	glib20 libxslt:build
USE_LDCONFIG=	yes
.if ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
.endif
BINARY_ALIAS=	python3=${PYTHON_VERSION}

MESON_ARGS=	-Dman=true \
		-Dgtk_doc=false \
		-Dvapi=true

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dconf/db
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dconf/profile

.include <bsd.port.mk>
