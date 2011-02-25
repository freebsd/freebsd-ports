# New ports collection makefile for:	DBIx::Skinny
# Date created:		19 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Skinny
PORTVERSION=	0.0740
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/N/NE/NEKOKAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple DBI wrapper/ORMapper

RUN_DEPENDS=	\
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-DBIx-TransactionManager>=1.07:${PORTSDIR}/databases/p5-DBIx-TransactionManager \
	p5-Class-Load>0:${PORTSDIR}/devel/p5-Class-Load
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Skinny.3 \
	DBIx::Skinny::Iterator.3 \
	DBIx::Skinny::Manual.3 \
	DBIx::Skinny::Manual::EN.3 \
	DBIx::Skinny::Manual::EN::Intro.3 \
	DBIx::Skinny::Manual::JA.3 \
	DBIx::Skinny::Manual::JA::Intro.3 \
	DBIx::Skinny::Manual::JA::Resultset.3 \
	DBIx::Skinny::Mixin.3 \
	DBIx::Skinny::Profiler.3 \
	DBIx::Skinny::Profiler::Trace.3 \
	DBIx::Skinny::Row.3 \
	DBIx::Skinny::SQL.3 \
	DBIx::Skinny::Schema.3

.include <bsd.port.mk>
