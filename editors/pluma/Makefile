PORTNAME=	pluma
PORTVERSION=	1.28.0
PORTREVISION=	2
CATEGORIES=	editors mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for MATE Desktop Environment
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libpeas-gtk-1.0.so:devel/libpeas1
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome libtool localbase \
		pathfix pkgconfig python shebangfix tar:xz xorg mate
USE_XORG=	ice sm x11
USE_GNOME=	cairo gdkpixbuf gnomeprefix gtk30 gtksourceview4 \
		intltool introspection libxml2
USE_MATE=	desktop:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	\
		${WRKSRC}/data/pluma-bugreport.sh.in \
		${WRKSRC}/plugins/externaltools/data/build.tool.in \
		${WRKSRC}/plugins/externaltools/data/open-terminal-here.tool.in \
		${WRKSRC}/plugins/externaltools/data/remove-trailing-spaces.tool.in \
		${WRKSRC}/plugins/externaltools/data/run-command.tool.in \
		${WRKSRC}/plugins/externaltools/data/search-recursive.tool.in \
		${WRKSRC}/plugins/externaltools/data/switch-c.tool.in
SHEBANG_LANG=	sh
sh_CMD=		/bin/sh

GLIB_SCHEMAS=	org.mate.pluma.gschema.xml \
		org.mate.pluma.plugins.filebrowser.gschema.xml \
		org.mate.pluma.plugins.pythonconsole.gschema.xml \
		org.mate.pluma.plugins.spell.gschema.xml \
		org.mate.pluma.plugins.time.gschema.xml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
