# Created by: TERAMOTO Masahiro <markun@onohara.to>
# $FreeBSD$

PORTNAME=	MouseX-Types-Path-Class
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MASAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Path::Class type library for Mouse

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mouse>=0.39:devel/p5-Mouse \
		p5-MouseX-Types>=0.02:devel/p5-MouseX-Types \
		p5-Path-Class>0:devel/p5-Path-Class \
		p5-MouseX-Getopt>=0.22:devel/p5-MouseX-Getopt
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-UseAllModules>0:devel/p5-Test-UseAllModules

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
