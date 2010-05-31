# New ports collection makefile for:	ristretto
# Date created:		2007-08-27
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ristretto
PORTVERSION=	0.0.22
PORTREVISION=	5
CATEGORIES=	graphics xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An image-viewer with xfce-integration

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_XFCE=	configenv libutil thunar

.include <bsd.port.mk>
