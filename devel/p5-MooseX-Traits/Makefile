# New ports collection makefile for:	MooseX-Traits
# Date created:	   11 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Traits
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Moose eXtenstion to automatically apply roles at object creation time

BUILD_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Mouse
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Traits.3

.include <bsd.port.mk>
