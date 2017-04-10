# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	igbinary
PORTVERSION=	2.0.1
CATEGORIES=	converters

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Replacement for the standard PHP serializer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:pecl

.include <bsd.port.pre.mk>

post-patch:
.if ${PHP_VER} >= 70
	${CP} ${WRKSRC}/src/php7/igbinary.h ${WRKSRC}/igbinary.h
	${CP} ${WRKSRC}/src/php7/php_igbinary.h ${WRKSRC}/php_igbinary.h
.else
	${CP} ${WRKSRC}/src/php5/igbinary.h ${WRKSRC}/igbinary.h
	${CP} ${WRKSRC}/src/php5/php_igbinary.h ${WRKSRC}/php_igbinary.h
.endif

.include <bsd.port.post.mk>
