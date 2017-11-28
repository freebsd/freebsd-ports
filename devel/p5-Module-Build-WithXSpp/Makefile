# Created by: Tomoyuki Sakurai <y@trombik.org>
# $FreeBSD$

PORTNAME=	Module-Build-WithXSpp
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	y@trombik.org
COMMENT=	XS++ enhanced flavour of Module::Build

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
#LICENSE_FILE=

BUILD_DEPENDS=	p5-ExtUtils-XSpp>0.11:devel/p5-ExtUtils-XSpp \
	p5-ExtUtils-CBuilder>0:devel/p5-ExtUtils-CBuilder \
	p5-Module-Build>=0.26:devel/p5-Module-Build \
	p5-ExtUtils-ParseXS>=2.2205:devel/p5-ExtUtils-ParseXS \
	p5-ExtUtils-CppGuess>=0.04:devel/p5-ExtUtils-CppGuess \
	p5-Digest-MD5>=0:security/p5-Digest-MD5
RUN_DEPENDS:= ${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	yes

.include <bsd.port.mk>
