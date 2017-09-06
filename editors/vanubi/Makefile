# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	vanubi
PORTVERSION=	0.0.16
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming editor written in Vala

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Vanubi is no longer actively maintained
EXPIRATION_DATE=	2017-10-06

BUILD_DEPENDS=	valac:lang/vala

GH_TAGNAME=	eedac1d

USE_GITHUB=	yes
USES=		autoreconf desktop-file-utils execinfo gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 gtksourceview3 libwnck3 vte3
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--without-asciidoc --disable-static

post-patch:
	${REINPLACE_CMD} -e 's|vte-2.90|vte-2.91|' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
