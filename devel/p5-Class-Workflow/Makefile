# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Class-Workflow
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lightweight workflow system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Compare>=0:devel/p5-Data-Compare \
		p5-Moose>=0.37:devel/p5-Moose \
		p5-MooseX-Clone>=0.04:devel/p5-MooseX-Clone \
		p5-Set-Object>=1.19:devel/p5-Set-Object \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
