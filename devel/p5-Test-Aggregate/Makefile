# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Aggregate
PORTVERSION=	0.373
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Aggregate Perl tests for better performance

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Test-Most>=0.21:devel/p5-Test-Most \
		p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings \
		p5-Test-Trap>0:devel/p5-Test-Trap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
