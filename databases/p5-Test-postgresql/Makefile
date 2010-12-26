# New ports collection makefile for:	Test::postgresql
# Date created:		26 Dec 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-postgresql
PORTVERSION=	0.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of postgresql runner for tests

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-DBD-Pg>0:${PORTSDIR}/databases/p5-DBD-Pg
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::postgresql.3

.include <bsd.port.mk>
