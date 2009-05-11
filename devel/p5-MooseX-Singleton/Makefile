# New ports collection makefile for:	MooseX-Singleton
# Date created:	   04 Jun 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Singleton
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Turn Moose class into a singleton

BUILD_DEPENDS=	p5-Moose>=0.74:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Singleton.3 MooseX::Singleton::Meta::Class.3 \
		MooseX::Singleton::Meta::Instance.3 MooseX::Singleton::Object.3

.include <bsd.port.mk>
