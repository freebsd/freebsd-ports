PORTNAME=	Tickit-Widgets
PORTVERSION=	0.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Abstract base class for on-screen widgets
WWW=		https://metacpan.org/release/Tickit-Widgets

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Object-Pad>=0.80.7:devel/p5-Object-Pad \
		p5-Parser-MGC>=0:devel/p5-Parser-MGC \
		p5-Syntax-Keyword-Dynamically>=0:devel/p5-Syntax-Keyword-Dynamically \
		p5-Tickit>=0.66:devel/p5-Tickit
TEST_DEPENDS=	p5-Test2-Suite>=0:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
