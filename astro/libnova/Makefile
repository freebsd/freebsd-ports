# ex:ts=8
# Ports collection makefile for:	libnova
# Date created:			Oct 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libnova
PORTVERSION=	0.12.3
CATEGORIES=	astro
MASTER_SITES=	SF

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Astronomical Calculation Library

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnometarget lthack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#post-extract:
#	@${TAR} xf ${WRKDIR}/${PORTNAME}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} -C ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
