# New ports collection makefile for:	wxsvg
# Date created:		2006-01-08
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/wxsvg/Makefile,v 1.1 2006/09/22 01:48:33 ahze Exp $

PORTNAME=	wxsvg
DISTVERSION=	1.0b6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	C++ library to create, manipulate, and render SVG files

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	libartlgpl2
USE_WX=		2.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' \
		${WRKSRC}/configure

pre-configure:
	cd ${WRKSRC} && ${LIBTOOLIZE} --copy --force

.include <bsd.port.post.mk>
