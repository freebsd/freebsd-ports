# New ports collection makefile for:	gxmame
# Date created:			04 Oct 2003
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	gxmame
PORTVERSION=	0.33
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tlp@liquidx.org
COMMENT=	GXmame is a GTK frontend for xmame

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext

USE_GZIP=	yes
USE_XLIB=	yes
USE_GNOME=	gtk12 gdkpixbuf glib12

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-joystick

.include <bsd.port.mk>
