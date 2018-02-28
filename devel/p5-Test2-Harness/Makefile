# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test2-Harness
PORTVERSION=	0.001053
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test2 Harness designed for the Test2 event system

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Importer>=0.024:devel/p5-Importer \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Term-Table>=0.011:devel/p5-Term-Table \
		p5-Test2-Suite>=0.000099:devel/p5-Test2-Suite \
		p5-goto-file>=0.005:devel/p5-goto-file
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502400
BUILD_DEPENDS+=	p5-File-Path>=2.11:devel/p5-File-Path
RUN_DEPENDS+=	p5-File-Path>=2.11:devel/p5-File-Path
.endif

.if ${PERL_LEVEL} < 502709
BUILD_DEPENDS+=	p5-Test-Simple>=1.302122:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.302122:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
