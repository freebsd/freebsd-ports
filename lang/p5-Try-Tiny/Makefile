PORTNAME=	Try-Tiny
PORTVERSION=	0.32
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minimal try/catch with proper localization of $$@
WWW=		https://metacpan.org/release/Try-Tiny

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.011:devel/p5-CPAN-Meta-Check \
		p5-Capture-Tiny>=0.12:devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
