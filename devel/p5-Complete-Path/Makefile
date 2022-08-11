PORTNAME=	Complete-Path
PORTVERSION=	0.251
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl routine for completing anything path-like

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Complete-Common>=0.22:devel/p5-Complete-Common \
		p5-Complete-Util>=0.608:devel/p5-Complete-Util \
		p5-Log-ger>=0.038:devel/p5-Log-ger

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
