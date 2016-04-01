# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	DBD-Mock
PORTVERSION=	1.45
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Simple mock DBD implementation used for testing

BUILD_DEPENDS=	p5-DBI>=1.3:databases/p5-DBI \
		p5-Test-Exception>=0.31:devel/p5-Test-Exception \
		p5-Test-Simple>=0.47:devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
