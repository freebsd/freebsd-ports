PORTNAME=	smuxi
PORTVERSION=	1.1
CATEGORIES=	irc
MASTER_SITES=	http://www.smuxi.org/jaws/data/files/

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Smart MUltipleXed Irc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/log4net.pc:devel/log4net \
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:devel/mono-addins \
		${LOCALBASE}/libdata/pkgconfig/nini-1.1.pc:devel/nini \
		bash:shells/bash \
		intltool-update:textproc/intltool
LIB_DEPENDS=	libstfl.so:devel/stfl
RUN_DEPENDS=	mono-addins>0:devel/mono-addins

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext-tools:build gmake gnome mono \
		pkgconfig
USE_GNOME=	gtksharp20

OPTIONS_DEFINE=		DBUS NLS SPELLCHECK
OPTIONS_DEFAULT=	DBUS NLS SPELLCHECK
OPTIONS_SUB=		yes

SPELLCHECK_DESC=	Spell checking support via GtkSpell

DBUS_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-2.0.pc:devel/dbus-sharp-glib \
			${LOCALBASE}/libdata/pkgconfig/gtk-sharp-3.0.pc:x11-toolkits/gtk-sharp30

SPELLCHECK_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

CONFIGURE_SHELL=	"env ${LOCALBASE}/bin/bash"

# Fails due to build order dependency issue.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
