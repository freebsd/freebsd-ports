# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	igbinary
PORTVERSION=	3.1.0
CATEGORIES=	converters

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement for the standard PHP serializer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:pecl

post-patch:	 
	@${CP} ${WRKSRC}/src/php7/igbinary.h ${WRKSRC}/igbinary.h
	@${CP} ${WRKSRC}/src/php7/php_igbinary.h ${WRKSRC}/php_igbinary.h

.include <bsd.port.mk>
