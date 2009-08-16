# New ports collection makefile for:	devel/p5-Class-Accessor-Chained
# Date created:				03 November 2004
# Whom:					mat
#
# $FreeBSD$
#

PORTNAME=	Class-Accessor-Chained
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Make chained accessors

RUN_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Accessor::Chained.3 \
		Class::Accessor::Chained::Fast.3

.include <bsd.port.mk>
