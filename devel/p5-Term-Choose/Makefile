PORTNAME=	Term-Choose
PORTVERSION=	1.783
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KUERBIS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Choose items from a list interactively
WWW=		https://metacpan.org/release/Term-Choose

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	XS
OPTIONS_DEFAULT=XS

XS_BUILD_RUN_DEPENDS=	p5-Term-Choose-LineFold-XS>=0.006:devel/p5-Term-Choose-LineFold-XS

.include <bsd.port.mk>
