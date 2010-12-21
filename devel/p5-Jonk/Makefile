# New ports collection makefile for:	Jonk
# Date created:		21 Dec 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jonk
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NE/NEKOKAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple job tank manager

RUN_DEPENDS=	\
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Jonk.3 \
	Jonk::Client.3 \
	Jonk::Cookbook.3 \
	Jonk::Cookbook::Basic.3 \
	Jonk::Cookbook::DequeueSpecificJob.3 \
	Jonk::Cookbook::ErrorHandling.3 \
	Jonk::Cookbook::ForkModel.3 \
	Jonk::Worker.3

.include <bsd.port.mk>
