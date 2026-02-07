PORTNAME=	Inline
PORTVERSION=	0.87
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Write Perl subroutines in other programming languages
WWW=		https://metacpan.org/release/Inline

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Parse-RecDescent>=1.800000:devel/p5-Parse-RecDescent
TEST_DEPENDS=	p5-Inline-Files>=0:devel/p5-Inline-Files \
		p5-Test-Warn>=0.23:devel/p5-Test-Warn

PORTSCOUT=	limit:^[0-9\.]*$$

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
