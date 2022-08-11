PORTNAME=	Test-Module-Used
PORTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TSUCCHI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tsucchi@cpan.org
COMMENT=	Test required module is really used and vice versa

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-List-MoreUtils>=0.24:lang/p5-List-MoreUtils \
		p5-Module-Used>=v1.2.0:devel/p5-Module-Used \
		p5-PPI>=1.205:textproc/p5-PPI

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
