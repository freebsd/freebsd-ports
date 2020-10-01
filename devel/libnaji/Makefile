# Created by: NECDET COKYAZICI <cokyazici@yahoo.co.uk>
# $FreeBSD$

PORTNAME=	libnaji
PORTVERSION=	0.6.4
DISTVERSIONSUFFIX=	.src
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/najitool/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library that generates, converts, and filters files

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	cc="${CC}"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libnaji.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libnaji.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
