# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Term-Size-Any
PORTVERSION=	0.002
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Retrieve terminal size

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-Hide>=0:devel/p5-Devel-Hide \
		p5-Term-Size-Perl>=0:devel/p5-Term-Size-Perl
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>=1.18:devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
