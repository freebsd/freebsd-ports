# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdk
PORTVERSION=	1.2.6
PORTREVISION=	2
CATEGORIES=	lang gnome
MASTER_SITES=	GNU/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities for developing programs using MIX and MIXAL

LICENSE=	GPLv3

USE_GNOME=	glib20 intltool
USES=		gettext ncurses readline gmake pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		mdk
PLIST_FILES=	bin/mixasm \
		bin/mixvm \
		share/locale/de/LC_MESSAGES/mdk.mo \
		%%DATADIR%%/mixal-mode.el \
		%%DATADIR%%/mixvm.el

OPTIONS_DEFINE=	GLADE GUILE
OPTIONS_DEFAULT=GLADE GUILE

GLADE_CONFIGURE_ENABLE=	gui
GLADE_USE=		GNOME=libglade2
GLADE_PLIST_FILES=	bin/gmixvm \
			%%DATADIR%%/mixgtk.glade

GUILE_CONFIGURE_WITH=	guile
GUILE_LIB_DEPENDS=	libguile.so:lang/guile
GUILE_PLIST_FILES=	bin/mixguile \
			%%DATADIR%%/mixguile.scm \
			%%DATADIR%%/mixguile-commands.scm \
			%%DATADIR%%/mixguile-vm-stat.scm

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
