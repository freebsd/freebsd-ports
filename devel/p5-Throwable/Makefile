# New ports collection makefile for:	Throwable
# Date created:				15 February 2010
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	Throwable
PORTVERSION=	0.100090
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/R/RJ/RJBS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An easy-to-use class for error objects

BUILD_DEPENDS=	p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace \
  				p5-ExtUtils-MakeMaker>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
				p5-Moose>=0.87:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS=	p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace \
  				p5-ExtUtils-MakeMaker>=0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
				p5-Moose>=0.87:${PORTSDIR}/devel/p5-Moose

MAN3=	Throwable.3 Throwable::Error.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
