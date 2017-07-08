# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test2-Suite
PORTVERSION=	0.000072
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Distribution with a rich set of tools built upon the Test2 framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Importer>=0.024:devel/p5-Importer \
		p5-Sub-Info>=0.001:devel/p5-Sub-Info \
		p5-Term-Table>=0.002:devel/p5-Term-Table
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502508
BUILD_DEPENDS+=	p5-Test-Simple>=1.302073:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.302073:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
