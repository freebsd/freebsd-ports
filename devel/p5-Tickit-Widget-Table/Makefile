# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Tickit-Widget-Table
PORTVERSION=	0.216
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Table widget with support for scrolling/paging

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Adapter-Async>=0.018:devel/p5-Adapter-Async \
		p5-String-Tagged>=0.09:textproc/p5-String-Tagged \
		p5-Tickit>=0.60:devel/p5-Tickit \
		p5-Tickit-Widgets>=0:devel/p5-Tickit-Widgets \
		p5-curry>=0:devel/p5-curry
TEST_DEPENDS=	p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
