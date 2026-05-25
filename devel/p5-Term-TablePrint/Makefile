PORTNAME=	Term-TablePrint
PORTVERSION=	0.182
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KUERBIS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Print a table to the terminal and browse it interactively
WWW=		https://metacpan.org/release/Term-TablePrint

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Term-Choose>=1.782:devel/p5-Term-Choose \
		p5-Term-Choose-LineFold-XS>=0.005:devel/p5-Term-Choose-LineFold-XS \
		p5-Term-Choose-Util>=0.148:devel/p5-Term-Choose-Util \
		p5-Term-Form>=0.563:devel/p5-Term-Form

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
