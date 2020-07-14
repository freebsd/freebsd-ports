# Created by: Romain Tartiere <romain@blogreen.org>
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
		bash:shells/bash \
		intltool-update:textproc/intltool
LIB_DEPENDS=	libstfl.so:devel/stfl
RUN_DEPENDS=	mono-addins>0:devel/mono-addins

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext-tools:build gmake gnome mono \
		pkgconfig
USE_GNOME=	gtksharp20
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		DBUS NLS SPELLCHECK
OPTIONS_DEFAULT=	DBUS NLS SPELLCHECK
oOPTIONS_SUB=		yes

SPELLCHECK_DESC=	Spell checking support via GtkSpell

DBUS_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:devel/ndesk-dbus \
			${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:devel/ndesk-dbus-glib
SPELLCHECK_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

CONFIGURE_SHELL=	"env ${LOCALBASE}/bin/bash"

# Fails due to build order dependency issue.
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
