# New ports collection makefile for:	Throwable
# Date created:				15 February 2010
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	Throwable
PORTVERSION=	0.102080
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An easy-to-use class for error objects

RUN_DEPENDS=	p5-Devel-StackTrace>=1.21:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		StackTrace::Auto.3 Throwable.3 Throwable::Error.3

.include <bsd.port.mk>
