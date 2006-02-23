# New ports collection makefile for:	wxsvg
# Date created:		2006-01-08
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wxsvg
DISTVERSION=	1.0b5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	C++ library to create, manipulate, and render SVG files

BUILD_DEPENDS=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/wxgtk26
RUN_DEPENDS=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/wxgtk26

INSTALLS_SHLIB=	yes
WX_CONFIG=	wxgtk2-2.6-config
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	libartlgpl2

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
