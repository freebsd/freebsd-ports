# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pluma
PORTVERSION=	1.22.1
PORTREVISION=	1
CATEGORIES=	editors mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for MATE Desktop Environment

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libpeas-gtk-1.0.so:devel/libpeas
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gmake gnome libtool localbase \
		pathfix pkgconfig python:3.3+ shebangfix tar:xz xorg
USE_XORG=	ice sm x11
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix gtk30 gtksourceview3 \
		gvfs intltool introspection libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	${WRKSRC}/plugins/externaltools/data/search-recursive.tool.in \
		${WRKSRC}/plugins/externaltools/data/switch-c.tool.in

GLIB_SCHEMAS=	org.mate.pluma.gschema.xml \
		org.mate.pluma.plugins.filebrowser.gschema.xml \
		org.mate.pluma.plugins.spell.gschema.xml \
                org.mate.pluma.plugins.time.gschema.xml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
