PORTNAME=	pluma
DISTVERSION=	1.28.1
CATEGORIES=	editors mate
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for MATE Desktop Environment
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libpeas-gtk-1.0.so:devel/libpeas1
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome libtool localbase \
		mate pathfix pkgconfig python shebangfix tar:xz xorg
USE_GITHUB=	nodefault
GH_ACCOUNT=	mate-desktop
USE_XORG=	ice sm x11
USE_GNOME=	cairo gdkpixbuf gnomeprefix gtk30 gtksourceview4 \
		intltool introspection libxml2
USE_MATE=	desktop common:build
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip

PORTSCOUT=	site:https://github.com/mate-desktop/pluma/releases/ limitw:1,even

SHEBANG_FILES=	\
		${WRKSRC}/data/pluma-bugreport.sh.in \
		${WRKSRC}/plugins/externaltools/data/build.tool.in \
		${WRKSRC}/plugins/externaltools/data/open-terminal-here.tool.in \
		${WRKSRC}/plugins/externaltools/data/remove-trailing-spaces.tool.in \
		${WRKSRC}/plugins/externaltools/data/run-command.tool.in \
		${WRKSRC}/plugins/externaltools/data/search-recursive.tool.in \
		${WRKSRC}/plugins/externaltools/data/switch-c.tool.in
SHEBANG_LANG=	sh
sh_CMD=		${SH}

GLIB_SCHEMAS=	org.mate.pluma.gschema.xml \
		org.mate.pluma.plugins.filebrowser.gschema.xml \
		org.mate.pluma.plugins.pythonconsole.gschema.xml \
		org.mate.pluma.plugins.spell.gschema.xml \
		org.mate.pluma.plugins.time.gschema.xml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
