# $FreeBSD$

PORTNAME=	MooX-HandlesVia
PORTVERSION=	0.001008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	NativeTrait-like behavior for Moo

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Perl>=0.002006:devel/p5-Data-Perl \
		p5-Moo>=1.003000:devel/p5-Moo
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-MooX-Types-MooseLike>=0.23:devel/p5-MooX-Types-MooseLike

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
