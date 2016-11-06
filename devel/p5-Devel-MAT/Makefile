# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Devel-MAT
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Memory Analysis Tool

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-List-UtilsBy>=0:devel/p5-List-UtilsBy \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Scalar-List-Utils>=1.44:lang/p5-Scalar-List-Utils \
		p5-Struct-Dumb>=0.07:devel/p5-Struct-Dumb
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Identity>=0:devel/p5-Test-Identity \
		p5-Test-Pod>=1:devel/p5-Test-Pod

USE_PERL5=	modbuild
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/MAT/Dumper/Dumper.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Devel/MAT/MAT.so

.include <bsd.port.mk>
