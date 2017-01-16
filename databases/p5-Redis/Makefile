# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Redis
PORTVERSION=	1.9820
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl binding for Redis database

LICENSE=	ART20

BUILD_DEPENDS=	p5-IO-Socket-Timeout>=0.29:net/p5-IO-Socket-Timeout \
		p5-Try-Tiny>=0.24:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-String>=0:devel/p5-IO-String \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-TCP>=0:devel/p5-Test-TCP \
		p5-Test-SharedFork>=0:devel/p5-Test-SharedFork

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
