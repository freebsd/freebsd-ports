# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Class-Workflow
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight workflow system

BUILD_DEPENDS=	p5-Moose>=0.37:${PORTSDIR}/devel/p5-Moose \
		p5-Set-Object>=1.19:${PORTSDIR}/devel/p5-Set-Object \
		p5-MooseX-Clone>=0.04:${PORTSDIR}/devel/p5-MooseX-Clone \
		p5-Data-Compare>=0:${PORTSDIR}/devel/p5-Data-Compare \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
