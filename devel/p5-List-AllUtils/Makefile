# $FreeBSD$

PORTNAME=	List-AllUtils
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Combines List::Util and List::MoreUtils in one bite-sized package

LICENSE=	ART20

# As of Perl 5.18, List::Util in core are earlier than 1.31
BUILD_DEPENDS=	p5-List-MoreUtils>=0.28:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Scalar-List-Utils>=1.31:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Warnings>=0:${PORTSDIR}/devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
