# $FreeBSD$

PORTNAME=	Alien-Build
PORTVERSION=	1.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build external dependencies for use in CPAN

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Which>=1.23:sysutils/p5-File-Which
TEST_DEPENDS=	p5-FFI-CheckLib>=0.23:devel/p5-FFI-CheckLib \
		p5-Readonly>=2.05:devel/p5-Readonly \
		p5-PkgConfig>=0.23026:devel/p5-PkgConfig \
		p5-PkgConfig-LibPkgConf>=0.10:devel/p5-PkgConfig-LibPkgConf

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
