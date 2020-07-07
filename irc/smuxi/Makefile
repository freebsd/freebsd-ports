# $FreeBSD$

PORTNAME=	smuxi
PORTVERSION=	1.0.8
CATEGORIES=	irc
MASTER_SITES=	http://www.smuxi.org/jaws/data/files/

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Smart MUltipleXed Irc

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/log4net.pc:devel/log4net \
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:devel/mono-addins \
		${LOCALBASE}/libdata/pkgconfig/nini-1.1.pc:devel/nini \
		intltool-update:textproc/intltool \
		bash:shells/bash
LIB_DEPENDS=	libstfl.so:devel/stfl
RUN_DEPENDS=	mono-addins>0:devel/mono-addins

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext-tools:build gmake gnome mono \
		pkgconfig
USE_GNOME=	gtksharp20
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		DBUS GTKSPELL NLS
OPTIONS_DEFAULT=	DBUS GTKSPELL NLS
OPTIONS_SUB=		yes

DBUS_DESC=	Build with DBUS support
GTKSPELL_DESC=	Support spell checking
NLS_DESC=	Build with NLS support

DBUS_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:devel/ndesk-dbus \
			${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:devel/ndesk-dbus-glib
GTKSPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

CONFIGURE_SHELL=	"env ${LOCALBASE}/bin/bash"

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
