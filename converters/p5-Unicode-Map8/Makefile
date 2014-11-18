# Created by: Ilia Chipitsine <ilia@jane.cgu.chel.su>
# $FreeBSD$

PORTNAME=	Unicode-Map8
PORTVERSION=	0.13
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mapping table between 8-bit chars and Unicode

BUILD_DEPENDS=	p5-Unicode-String>=2:${PORTSDIR}/converters/p5-Unicode-String
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
	${CHMOD} u+w ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Unicode/Map8/Map8.so
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Unicode/Map8/Map8.so
	${CHMOD} u-w ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Unicode/Map8/Map8.so

.include <bsd.port.mk>
