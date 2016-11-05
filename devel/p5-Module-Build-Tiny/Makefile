# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$
#
# If you have compelling evidence that some ports need at least this version of
# p5-Module-Build-Tiny to build, be sure to update the BUILD_DEPENDS version in
# Mk/Uses/perl5.mk.

PORTNAME=	Module-Build-Tiny
PORTVERSION=	0.039
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny replacement for Module::Build

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Config>=0.003:devel/p5-ExtUtils-Config \
		p5-ExtUtils-Helpers>=0.020:devel/p5-ExtUtils-Helpers \
		p5-ExtUtils-InstallPaths>=0.002:devel/p5-ExtUtils-InstallPaths
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	modbuildtiny
USES=		perl5

.include <bsd.port.mk>
