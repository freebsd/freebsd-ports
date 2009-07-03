# New ports collection makefile for:	namespace-autoclean
# Date created:	   13 May 2009
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	namespace-autoclean
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Keep imports out of your namespace

BUILD_DEPENDS=	p5-Class-MOP>=0.80:${PORTSDIR}/devel/p5-Class-MOP \
		p5-B-Hooks-EndOfScope>=0.07:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-namespace-clean>=0.11:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		namespace::autoclean.3

.include <bsd.port.mk>
