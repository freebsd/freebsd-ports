# New ports collection makefile for:	Iterator-Misc
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Iterator-Misc
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Miscellaneous iterator functions

BUILD_DEPENDS=	${SITE_PERL}/Iterator.pm:${PORTSDIR}/devel/p5-Iterator
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	Iterator::Misc.3

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
