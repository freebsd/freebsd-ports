# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	thunar-media-tags-plugin
PORTVERSION=	0.2.1
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/thunar-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Media Tags Plugin

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib

USES=		gmake pkgconfig gettext
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libexo thunar
USE_AUTOTOOLS=	libtool

.include <bsd.port.mk>
