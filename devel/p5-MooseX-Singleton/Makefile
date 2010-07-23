# New ports collection makefile for:	MooseX-Singleton
# Date created:	   04 Jun 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	MooseX-Singleton
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Turn Moose class into a singleton

BUILD_DEPENDS=	p5-Moose>=0.94:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		MooseX::Singleton.3 \
		MooseX::Singleton::Role::Meta::Class.3 \
		MooseX::Singleton::Role::Meta::Instance.3 \
		MooseX::Singleton::Role::Meta::Method::Constructor.3 \
		MooseX::Singleton::Role::Object.3

.include <bsd.port.mk>
