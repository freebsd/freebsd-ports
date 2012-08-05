# ex:ts=8
# New ports collection makefile for:  mdk
# Date created:			Apr 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdk
PORTVERSION=	1.2.6
CATEGORIES=	lang gnome
MASTER_SITES=	GNU/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities for developing programs using MIX and MIXAL

LICENSE=	GPLv3

OPTIONS_DEFINE=	GLADE GUILE
OPTIONS_DEFAULT=GLADE GUILE

USE_GNOME=	glib20 intltool
USE_NCURSES=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		mdk
PLIST_FILES=	bin/mixasm \
		bin/mixvm \
		share/locale/de/LC_MESSAGES/mdk.mo \
		%%DATADIR%%/mixal-mode.el \
		%%DATADIR%%/mixvm.el
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLADE}
USE_GNOME+=	libglade2
PLIST_FILES+=	bin/gmixvm \
		%%DATADIR%%/mixgtk.glade
.else
CONFIGURE_ARGS+=--disable-gui
.endif

.if ${PORT_OPTIONS:MGUILE}
LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
PLIST_FILES+=	bin/mixguile \
		%%DATADIR%%/mixguile.scm \
		%%DATADIR%%/mixguile-commands.scm \
		%%DATADIR%%/mixguile-vm-stat.scm
.else
CONFIGURE_ARGS+=--without-guile
.endif

.if exists(${LOCALBASE}/lib/libreadline.so)
LIB_DEPENDS+=	readline:${PORTSDIR}/devel/readline
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
