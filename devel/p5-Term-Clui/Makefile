# $FreeBSD$

PORTNAME=	Term-Clui
PORTVERSION=	1.76
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module offering a Command-Line User Interface

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu \
		p5-Term-Size>=0:devel/p5-Term-Size

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
