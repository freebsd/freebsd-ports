# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test2-Harness
PORTVERSION=	1.000006
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
		p5-Importer>=0.025:devel/p5-Importer \
		p5-Long-Jump>=0.000001:devel/p5-Long-Jump \
		p5-Scope-Guard>=0:devel/p5-Scope-Guard \
		p5-Term-Table>=0.015:devel/p5-Term-Table \
		p5-Test-Simple>=1.302170:devel/p5-Test-Simple \
		p5-Test2-Plugin-MemUsage>=0.002002:devel/p5-Test2-Plugin-MemUsage \
		p5-Test2-Plugin-UUID>=0.002001:devel/p5-Test2-Plugin-UUID \
		p5-Test2-Suite>=0.000127:devel/p5-Test2-Suite \
		p5-goto-file>=0.005:devel/p5-goto-file

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
