# Created by: Alexey V. Degtyarev
# $FreeBSD$

PORTNAME=	File-ChangeNotify
PORTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Watch for changes to files

LICENSE=	ART20

RUN_DEPENDS=	p5-Moose>=2:devel/p5-Moose \
		p5-IO-KQueue>=0:devel/p5-IO-KQueue \
		p5-MooseX-Params-Validate>=0:devel/p5-MooseX-Params-Validate \
		p5-MooseX-SemiAffordanceAccessor>=0:devel/p5-MooseX-SemiAffordanceAccessor \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
