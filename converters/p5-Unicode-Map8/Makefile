# Created by: Ilia Chipitsine <ilia@jane.cgu.chel.su>
# $FreeBSD$

PORTNAME=	Unicode-Map8
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mapping table between 8-bit chars and Unicode

BUILD_DEPENDS=	p5-Unicode-String>=2:converters/p5-Unicode-String
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Unicode/Map8/Map8.so

.include <bsd.port.mk>
