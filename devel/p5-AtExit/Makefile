# New ports collection makefile for:	AtExit
# Date created:	   28 August 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	AtExit
PORTVERSION=	2.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRADAPP
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INSTALLDIRS=site

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		AtExit.3

.include <bsd.port.mk>
