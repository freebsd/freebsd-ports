# New ports collection makefile for:    p5-Date-Set
# Date created:                         Thu Jan  8 13:16:46 PST 2004
# Whom:                                 mharo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Date-Set
PORTVERSION=	1.30
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Date
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	A module for date/time sets

BUILD_DEPENDS=	${SITE_PERL}/Set/Infinite.pm:${PORTSDIR}/devel/p5-Set-Infinite \
		${SITE_PERL}/Date/ICal.pm:${PORTSDIR}/devel/p5-Date-ICal
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Date::Set::ICal.3 Date::Set.3

.include <bsd.port.mk>
