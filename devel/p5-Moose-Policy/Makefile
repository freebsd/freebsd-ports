# New ports collection makefile for:	Moose-Policy
# Date created:	   25 February 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Moose-Policy
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/ST/STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Moose-mounted police

RUN_DEPENDS=	${SITE_PERL}/Moose.pm:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS=	${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception \
		${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Moose::Policy.3 Moose::Policy::FollowPBP.3 \
		Moose::Policy::JavaAccessors.3 \
		Moose::Policy::SingleInheritence.3

.include <bsd.port.mk>
