# New ports collection makefile for:	p5-B-Hooks-OP-Annotation
# Date created:		2011-08-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	B-Hooks-OP-Annotation
PORTVERSION=	0.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Annotate and delegate hooked OPs

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.304:${PORTSDIR}/devel/p5-ExtUtils-Depends
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		B::Hooks::OP::Annotation.3

.include <bsd.port.mk>
