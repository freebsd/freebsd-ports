# New ports collection makefile for:	gxmame
# Date created:			04 Oct 2003
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	gxmame
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://shell.n.ml.org/n/tlp/
PATCHFILES=	gxmame-0.33-xmame074.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tlp@liquidx.org
COMMENT=	GXmame is a GTK frontend for xmame

RUN_DEPENDS=	xmame:${PORTSDIR}/emulators/xmame
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext

USE_GZIP=	yes
USE_XLIB=	yes
USE_GNOME=	gtk12 gdkpixbuf glib12

DOCDIR=		share/doc/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-joystick

.include <bsd.port.mk>
