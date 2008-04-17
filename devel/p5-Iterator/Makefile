# New ports collection makefile for:	Iterator
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Iterator
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A general-purpose iterator class

BUILD_DEPENDS=	${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	Iterator.3

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
