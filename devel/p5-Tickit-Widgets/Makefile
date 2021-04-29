# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Tickit-Widgets
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Abstract base class for on-screen widgets

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Parser-MGC>=0:devel/p5-Parser-MGC \
		p5-Struct-Dumb>=0:devel/p5-Struct-Dumb \
		p5-Tickit>=0.57:devel/p5-Tickit
TEST_DEPENDS=	p5-Test-Identity>=0:devel/p5-Test-Identity \
		p5-Test-Refcount>=0:devel/p5-Test-Refcount

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
