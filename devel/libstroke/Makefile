# New ports collection makefile for:	LibStroke
# Date created:				31 December 2001
# Whom:					Jerry A! <jerry@thehutt.org>
#
# $FreeBSD$
#

PORTNAME=	libstroke
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.etla.net/libstroke/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A stroke translation library

USE_XORG=	x11
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
WANT_GNOME=	yes
USE_LDCONFIG=	yes

OPTIONS=	GTK	"Build with legacy Gtk+/GNOME stroke support"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK) || ${HAVE_GNOME:Mgtk12}
USE_GNOME+=	gtk12
PLIST_SUB+=	GS=""
.else
PLIST_SUB+=	GS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
			${WRKSRC}/configure

.include <bsd.port.post.mk>
