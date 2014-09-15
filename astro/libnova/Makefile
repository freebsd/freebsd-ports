# Created by: ijliao
# $FreeBSD$

PORTNAME=	libnova
PORTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v%20${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Astronomical Calculation Library

GNU_CONFIGURE=	yes
USES=		libtool
USE_AUTOTOOLS=	aclocal autoheader autoconf automake libtoolize
AUTOMAKE_ARGS=	-a -c -f
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
