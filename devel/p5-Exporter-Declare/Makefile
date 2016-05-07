# $FreeBSD$

PORTNAME=	Exporter-Declare
PORTVERSION=	0.114
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for exporting done right

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Meta-Builder>=0.003:devel/p5-Meta-Builder \
	p5-aliased>0:devel/p5-aliased
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Fennec-Lite>=0:devel/p5-Fennec-Lite \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=	perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
