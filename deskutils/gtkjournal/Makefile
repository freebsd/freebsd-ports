# New ports collection makefile for:	gtkjournal
# Date created:				08 February 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkjournal
PORTVERSION=	0.3.5.b
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://linuxhelp.homeunix.com/gtkjournal/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Gtk+-2 journal/diary

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2 \
		sqlite.2:${PORTSDIR}/databases/sqlite2 \
		gtkspell:${PORTSDIR}/textproc/gtkspell2

USE_X_PREFIX=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
USE_GNOME=	gnomehack lthack gnometarget
CONFIGURE_ARGS=	--enable-gtkspell
INSTALLS_SHLIB=	yes

MAN1=		${PORTNAME}.1

.include <bsd.port.mk>
