PORTNAME=	Tickit-Widgets
PORTVERSION=	0.35
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
RUN_DEPENDS=	p5-Object-Pad>=0.63:devel/p5-Object-Pad \
		p5-Parser-MGC>=0:devel/p5-Parser-MGC \
		p5-Syntax-Keyword-Dynamically>=0:devel/p5-Syntax-Keyword-Dynamically \
		p5-Tickit>=0.66:devel/p5-Tickit
TEST_DEPENDS=	p5-Test-Identity>=0:devel/p5-Test-Identity \
		p5-Test-Refcount>=0:devel/p5-Test-Refcount

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
