PORTNAME=	Log-Report-Template
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Template Toolkit with translations
WWW=		https://metacpan.org/dist/Log-Report-Template

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Report>=1.42:devel/p5-Log-Report \
		p5-Log-Report-Lexicon>=1.13:devel/p5-Log-Report-Lexicon \
		p5-String-Print>=0.91:textproc/p5-String-Print \
		p5-Template-Toolkit>=2.26:www/p5-Template-Toolkit

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
