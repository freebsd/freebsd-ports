# New ports collection makefile for:	DBIx::Skinny::Pager
# Date created:		20 Nov 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Skinny-Pager
PORTVERSION=	0.11
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of resultset pager for DBIx::Skinny

RUN_DEPENDS=	\
	p5-DBIx-Skinny>=0.0729:${PORTSDIR}/databases/p5-DBIx-Skinny \
	p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page \
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Skinny::Mixin::Pager.3 \
	DBIx::Skinny::Mixin::SearchWithPager.3 \
	DBIx::Skinny::Pager.3 \
	DBIx::Skinny::Pager::Logic::Count.3 \
	DBIx::Skinny::Pager::Logic::MySQLFoundRows.3 \
	DBIx::Skinny::Pager::Logic::PlusOne.3 \
	DBIx::Skinny::Pager::Page.3

.include <bsd.port.mk>
