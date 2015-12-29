# Created by: NECDET COKYAZICI <cokyazici@yahoo.co.uk>
# $FreeBSD$

PORTNAME=	libnaji
PORTVERSION=	0.6.4
DISTVERSIONSUFFIX=	.src
CATEGORIES=	devel
MASTER_SITES=	SF/najitool/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library that generates, converts, and filters files

MAKE_ARGS=	cc="${CC}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libnaji.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libnaji.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
