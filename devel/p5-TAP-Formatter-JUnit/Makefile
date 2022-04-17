PORTNAME=	TAP-Formatter-JUnit
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for Harness output delegate for JUnit output

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-NonMoose>=0:devel/p5-MooseX-NonMoose \
		p5-XML-Generator>=0:textproc/p5-XML-Generator \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-Test-DiagINC>=0.002:devel/p5-Test-DiagINC \
		p5-Test-XML>=0:devel/p5-Test-XML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
