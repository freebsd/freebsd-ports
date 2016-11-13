# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	match-simple
PORTVERSION=	0.009
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified clone of smartmatch operator

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Tiny>=0.026:devel/p5-Exporter-Tiny \
		p5-Sub-Infix>=0.004:devel/p5-Sub-Infix
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
