# New ports collection makefile for:	Iterator-Util
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Iterator-Util
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Essential utilities for the Iterator class

BUILD_DEPENDS=	${SITE_PERL}/Iterator.pm:${PORTSDIR}/devel/p5-Iterator
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	Iterator::Util.3

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
