PORTNAME=	Log-Report
PORTVERSION=	1.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Report a problem, pluggable handlers and language support
WWW=		https://metacpan.org/release/Log-Report

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-GlobalDestruction>=0.09:devel/p5-Devel-GlobalDestruction \
		p5-Log-Report-Optional>=1.07:devel/p5-Log-Report-Optional \
		p5-String-Print>=1.00:textproc/p5-String-Print

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
