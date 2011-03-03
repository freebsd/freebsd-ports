# New ports collection makefile for:	thunar-media-tags-plugin
# Date created:				24 Januar 2006
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	thunar-media-tags-plugin
PORTVERSION=	0.1.2
PORTREVISION=	16
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/thunar-plugins//${PORTNAME}/${PORTVERSION:R}
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
USE_XFCE=	configenv libexo thunar thunarvfs
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|exo-0\.3|exo-1|g; \
		s|thunarx-1|thunarx-2|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
