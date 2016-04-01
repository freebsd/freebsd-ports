# Created by: ijliao
# $FreeBSD$

PORTNAME=	v6
PORTVERSION=	0.017
PORTREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FGLOCK
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Experimental compiler for Perl 6

BUILD_DEPENDS=	p5-Data-Bind>=0.28:devel/p5-Data-Bind \
		p5-Devel-Caller>=0.10:devel/p5-Devel-Caller \
		p5-Module-Compile>=0.20:devel/p5-Module-Compile \
		p5-Moose>=0.10:devel/p5-Moose \
		p5-Pugs-Compiler-Rule>=0.17:lang/p5-Pugs-Compiler-Rule \
		p5-Sub-Multi>=0:devel/p5-Sub-Multi \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
