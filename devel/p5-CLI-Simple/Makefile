PORTNAME=	CLI-Simple
DISTVERSION=	2.0.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BIGFOOT
PKGNAMEPREFIX=	p5-

MAINTAINER=	einar@isnic.is
COMMENT=	Minimalist object oriented base class for CLI applications
WWW=		https://metacpan.org/pod/CLI::Simple

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

MY_DEPENDS=	p5-Class-Accessor>=0.51:devel/p5-Class-Accessor \
		p5-File-ShareDir>=1.118:devel/p5-File-ShareDir \
		p5-File-ShareDir-Install>0:devel/p5-File-ShareDir-Install \
		p5-File-Which>=1.23:sysutils/p5-File-Which \
		p5-JSON>=4.07:converters/p5-JSON \
		p5-Log-Log4perl>=1.57:devel/p5-Log-Log4perl \
		p5-Readonly>=2.05:devel/p5-Readonly \
		p5-Role-Tiny>0:devel/p5-Role-Tiny \
		p5-YAML-Tiny>=1.76:textproc/p5-YAML-Tiny
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}
TEST_DEPENDS=	p5-Role-Tiny>=2.002004:devel/p5-Role-Tiny \
		p5-Test-Exit>=0.11:devel/p5-Test-Exit \
		p5-Test-Output>=1.036:devel/p5-Test-Output \
		p5-YAML-Tiny>=1.76:textproc/p5-YAML-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-extract:
	${RM} ${WRKSRC}/postamble

.include <bsd.port.mk>
