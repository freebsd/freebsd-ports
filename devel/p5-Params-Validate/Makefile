# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	Params-Validate
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Validate method/function parameters

LICENSE=	ART20

BUILD_DEPENDS=	p5-Module-Implementation>=0.04:${PORTSDIR}/devel/p5-Module-Implementation
RUN_DEPENDS=	p5-Module-Implementation>=0.04:${PORTSDIR}/devel/p5-Module-Implementation
TEST_DEPENDS=	p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Taint>=0.02:${PORTSDIR}/devel/p5-Test-Taint

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
