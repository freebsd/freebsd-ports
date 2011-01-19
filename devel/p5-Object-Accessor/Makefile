# New ports collection makefile for:	Object-Accessor
# Date created:	   30 September 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Object-Accessor
PORTVERSION=	0.38
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/B/BI/BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to create per object accessors

RUN_DEPENDS=	${SITE_PERL}/Params/Check.pm:${PORTSDIR}/devel/p5-Params-Check
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Object::Accessor.3

.include <bsd.port.mk>
