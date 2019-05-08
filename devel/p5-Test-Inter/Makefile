# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Inter
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Framework for more readable interactive test scripts

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Find-Rule>0:devel/p5-File-Find-Rule
TEST_DEPENDS=	p5-Test-Pod>=1.00:devel/p5-Test-Pod \
		p5-Pod-Coverage>=1.00:devel/p5-Pod-Coverage

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
