# New ports collection makefile for:	p5-TimeDate
# Version required:		1.08
# Date created:			Mon Sep  1 17:03:41 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.2 1997/10/04 14:53:08 andreas Exp $
#

DISTNAME=	TimeDate-1.08
PKGNAME=	p5-TimeDate-1.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date

MAINTAINER=	andreas@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		Date::Format.3 Date::Parse.3 Time::Zone.3

MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
