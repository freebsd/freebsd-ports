# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gucharmap
PORTVERSION=	9.0.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode/ISO10646 character map and font viewer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		UCD>=0:textproc/UCD

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gmake gnome libtool localbase \
		pathfix pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool introspection:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unicode-data=${LOCALBASE}/share/unicode/ucd/
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Charmap.enums.xml \
		org.gnome.Charmap.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
