# New ports collection makefile for:	p5-TimeDate
# Date created:			Mon Sep  1 17:03:41 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	TimeDate
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	dima@Chg.RU

USE_PERL5=	YES

MAN3=		Date::Format.3 \
		Date::Parse.3 \
		Time::Zone.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
