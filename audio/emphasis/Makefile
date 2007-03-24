# New ports collection makefile for:	emphasis
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	emphasis
PORTVERSION=	20070223
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A simple MPD (Music Player Daemon) client written in C/Etk

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd
BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel
BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget libxml2
USE_EFL=	ecore enhance etk
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
