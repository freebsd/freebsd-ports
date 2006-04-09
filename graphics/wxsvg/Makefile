# New ports collection makefile for:	wxsvg
# Date created:		2006-01-08
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wxsvg
DISTVERSION=	1.0b6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	C++ library to create, manipulate, and render SVG files

BUILD_DEPENDS=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/wxgtk26
RUN_DEPENDS=	${WX_CONFIG}:${PORTSDIR}/x11-toolkits/wxgtk26

INSTALLS_SHLIB=	yes
WX_CONFIG=	wxgtk2-2.6-config
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	libartlgpl2

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' \
		${WRKSRC}/configure
	cd ${WRKSRC} && ${LIBTOOLIZE} --copy --force

.include <bsd.port.post.mk>
