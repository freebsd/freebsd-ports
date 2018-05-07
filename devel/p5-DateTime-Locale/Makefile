# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Locale
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Localization support for DateTime

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Dist-CheckConflicts>=0.02:devel/p5-Dist-CheckConflicts \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Params-ValidationCompiler>=0.13:devel/p5-Params-ValidationCompiler \
		p5-Specio>=0:devel/p5-Specio \
		p5-namespace-autoclean>=0.19:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CPAN-Meta-Check>=0.011:devel/p5-CPAN-Meta-Check \
		p5-IPC-System-Simple>=0:devel/p5-IPC-System-Simple \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-File-ShareDir>=0:devel/p5-Test-File-ShareDir \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings
BUILD_DEPENDS+=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502501
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
