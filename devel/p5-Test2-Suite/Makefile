# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test2-Suite
PORTVERSION=	0.000094
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Distribution with a rich set of tools built upon the Test2 framework

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Importer>=0.024:devel/p5-Importer \
		p5-Module-Pluggable>=2.7:devel/p5-Module-Pluggable \
		p5-Scope-Guard>=0:devel/p5-Scope-Guard \
		p5-Sub-Info>=0.002:devel/p5-Sub-Info \
		p5-Term-Table>=0.002:devel/p5-Term-Table \
		p5-Test-Simple>=1.302119:devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
