# New ports collection makefile for:	chbg
# Date created:		10 Dec 1999
# Whom:			Peter Jones <p@dancris.com>
#
# $FreeBSD$
#

PORTNAME=	chbg
PORTVERSION=	0.8.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.idata.sk/~ondrej/sw/
DISTNAME=	${PORTNAME}-0.8pl1
EXTRACT_SUFX=	.tgz

MAINTAINER=	p@dancris.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.5:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

.include <bsd.port.mk>
