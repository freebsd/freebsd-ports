# ex:ts=8
# Ports collection makefile for:	libnova
# Date created:			Oct 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libnova
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomical Calculation Library

USE_GNOME=	gnometarget lthack
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
