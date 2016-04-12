# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO-Any
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	IO::Any opens anything

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Distribution>=0:devel/p5-Test-Distribution \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Fixme>=0:devel/p5-Test-Fixme \
		p5-Test-Pod>=1.22:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.08:devel/p5-Test-Pod-Coverage

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
