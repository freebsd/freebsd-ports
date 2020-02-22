# $FreeBSD$

PORTNAME=	Alien-Build
PORTVERSION=	2.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build external dependencies for use in CPAN

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0.17:devel/p5-Capture-Tiny \
		p5-FFI-CheckLib>=0.11:devel/p5-FFI-CheckLib \
		p5-File-Which>=1.10:sysutils/p5-File-Which \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-Path-Tiny>=0.077:devel/p5-Path-Tiny
TEST_DEPENDS=	p5-PkgConfig>=0.14026:devel/p5-PkgConfig \
		p5-PkgConfig-LibPkgConf>=0.04:devel/p5-PkgConfig-LibPkgConf \
		p5-Readonly>=1.60:devel/p5-Readonly \
		p5-Test2-Suite>=0.000060:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502800
BUILD_DEPENDS+=	p5-Test-Simple>=1.302096:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.302096:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
