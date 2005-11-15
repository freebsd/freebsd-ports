# ex:ts=8
# Ports collection makefile for:	libnova
# Date created:			Oct 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libnova
PORTVERSION=	0.11.0
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomical Calculation Library

USE_GNOME=	gnometarget lthack
USE_REINPLACE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
USE_GCC=	3.3

.include <bsd.port.pre.mk>

.if ${OSVERSION}<503000
IGNORE=		Requires FreeBSD 5.3 or higher
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
