PORTNAME=	App-CLI
DISTVERSION=	0.510
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PTC
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${DISTVERSION:S|0$||}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dispatcher Perl module for command-line programs
WWW=		https://metacpan.org/release/App-CLI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Class-Load>=0:devel/p5-Class-Load
TEST_DEPENDS=	p5-Test-Kwalitee>=0:devel/p5-Test-Kwalitee \
		p5-Test-Pod>=0:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
