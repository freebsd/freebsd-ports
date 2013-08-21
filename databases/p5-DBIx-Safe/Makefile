# New ports collection makefile for:	p5-DBIx-Safe
# Date created:		2011-12-05
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Safe
PORTVERSION=	1.2.5
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TURNSTEP
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Safer access to your database through a DBI database handle

BUILD_DEPENDS=	p5-DBD-Pg>=1.49:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-DBI>=1.490:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	p5-DBD-Pg>=1.49:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-DBI>=1.490:${PORTSDIR}/databases/p5-DBI

USE_PERL5=	configure
USES=		perl5

MAN3=		DBIx::Safe.3

.include <bsd.port.mk>
