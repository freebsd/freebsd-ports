# New ports collection makefile for:	thunar-media-tags-plugin
# Date created:				24 Januar 2006
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	thunar-media-tags-plugin
PORTVERSION=	0.1.2
PORTREVISION=	9
CATEGORIES=	audio xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A Media Tags Plugin

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gnomehack gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libexo thunar
USE_AUTOTOOLS=	libtool:15

.include <bsd.port.mk>
