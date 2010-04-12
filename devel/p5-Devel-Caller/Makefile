# ex:ts=8
# Ports collection makefile for:	Devel-Caller
# Date created:			Jul. 11, 2006
# Whom:				Ying-Chieh Chen
#
# $FreeBSD$
#

PORTNAME=	Devel-Caller
PORTVERSION=	2.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl module which is meatier versions of caller

RUN_DEPENDS=	p5-PadWalker>=0.08:${PORTSDIR}/devel/p5-PadWalker
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Devel::Caller.3

.include <bsd.port.mk>
