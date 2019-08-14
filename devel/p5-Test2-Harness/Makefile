# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test2-Harness
PORTVERSION=	0.001081
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test2 Harness designed for the Test2 event system

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-UUID>=1.148:devel/p5-Data-UUID \
		p5-Importer>=0.024:devel/p5-Importer \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Term-Table>=0.011:devel/p5-Term-Table \
		p5-Test-Simple>=1.302133:devel/p5-Test-Simple \
		p5-Test2-Suite>=0.000105:devel/p5-Test2-Suite \
		p5-goto-file>=0.005:devel/p5-goto-file

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
