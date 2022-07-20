PORTNAME=	Method-Signatures
PORTVERSION=	20170211
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BAREFOOT
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Method and function declarations with signatures and no source filter

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Any-Moose>=0.11:devel/p5-Any-Moose \
		p5-Const-Fast>=0.006:devel/p5-Const-Fast \
		p5-Devel-Declare>=0.006002:devel/p5-Devel-Declare \
		p5-Lexical-SealRequireHints>=0.008:devel/p5-Lexical-SealRequireHints \
		p5-Mouse>=0.64:devel/p5-Mouse \
		p5-PPI>=1.203:textproc/p5-PPI \
		p5-Sub-Name>=0.03,1:devel/p5-Sub-Name
TEST_DEPENDS=	p5-Test-Exception>=0.29:devel/p5-Test-Exception \
		p5-Test-Warn>=0.10:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
