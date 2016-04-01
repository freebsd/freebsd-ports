# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	String-Diff
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple diff to String

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Base>=0:devel/p5-Test-Base \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
