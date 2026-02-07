PORTNAME=	Tie-Sub
PORTVERSION=	1.001
CATEGORIES=	devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Tying a subroutine, function or method to a hash
WWW=		https://metacpan.org/release/Tie-Sub

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Params-Validate>0:devel/p5-Params-Validate
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Test-Perl-Critic>=0:textproc/p5-Test-Perl-Critic \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
		p5-Test-Pod>0:devel/p5-Test-Pod

USES=		perl5 # dos2unix: test not work #
USE_PERL5=	configure

PLIST_FILES=	${SITE_MAN3_REL}/Tie::Sub.3.gz \
		${SITE_PERL_REL}/Tie/Sub.pm

NO_ARCH=	yes
TEST_ENV=	AUTHOR_TESTING=1 # RELEASE_TESTING=1: test not work #

.include <bsd.port.mk>
