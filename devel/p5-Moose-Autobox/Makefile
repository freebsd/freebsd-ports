# Created by: Bill Brinzer <bill.brinzer@gmail.com>
# $FreeBSD$

PORTNAME=	Moose-Autobox
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Autoboxed wrappers for Native Perl datatypes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-autobox>=2.23:devel/p5-autobox \
		p5-Moose>=0.42:devel/p5-Moose \
		p5-Syntax-Keyword-Junction>=0:devel/p5-Syntax-Keyword-Junction
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.21:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
