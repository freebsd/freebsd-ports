# New ports collection makefile for:	Qudo
# Date created:		27 Jun 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Qudo
PORTVERSION=	0.0213
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NE/NEKOKAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple and extensible job queue manager

RUN_DEPENDS=	\
	p5-Class-Data-Inheritable>0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-DBIx-Skinny>0:${PORTSDIR}/databases/p5-DBIx-Skinny \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Qudo.3 \
	Qudo::Manager.3 \
	Qudo::Manual::JA::Functions.3 \
	Qudo::Manual::JA::Intro.3 \
	Qudo::Manual::JA::Tutorial.3 \
	Qudo::Worker.3

.include <bsd.port.mk>
