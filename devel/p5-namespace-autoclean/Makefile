# New ports collection makefile for:	namespace-autoclean
# Date created:	   13 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	namespace-autoclean
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BOBTFISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Keep imports out of your namespace

RUN_DEPENDS=	p5-B-Hooks-EndOfScope>=0:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-Moose>=1.00:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-clean>=0.20:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		namespace::autoclean.3

.include <bsd.port.mk>
