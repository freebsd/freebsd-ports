# New ports collection makefile for:	p5-Date-Roman
# Date created:				16 January 2003
# Whom:	      				Philip Paeps <philip@paeps.cx>
#
# $FreeBSD$
#

PORTNAME=	Date-Roman
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Perl module to play with Roman dates

BUILD_DEPENDS=	${SITE_PERL}/Roman.pm:${PORTSDIR}/math/p5-Roman
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Date::Roman.3

.include <bsd.port.mk>
