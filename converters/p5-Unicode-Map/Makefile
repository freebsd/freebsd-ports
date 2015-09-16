# Created by: Ryan T. Dean <rtdean@cytherianage.net>
# $FreeBSD$

PORTNAME=	Unicode-Map
PORTVERSION=	0.112
PORTREVISION=	2
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl class that converts strings to/from 2-byte Unicode UCS2 format

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Unicode/Map/Map.so

.include <bsd.port.mk>
