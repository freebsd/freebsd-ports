# New ports collection makefile for:	Class-DBI-Lite
# Date created:				16th March, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Lite
PORTVERSION=	1.023
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight ORM for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Cache-Memcached>=1.27:${PORTSDIR}/databases/p5-Cache-Memcached \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBIx-ContextualFetch>=0:${PORTSDIR}/databases/p5-DBIx-ContextualFetch \
		p5-Ima-DBI-Contextual>=0:${PORTSDIR}/databases/p5-Ima-DBI-Contextual \
		p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract \
		p5-SQL-Abstract-Limit>=0:${PORTSDIR}/databases/p5-SQL-Abstract-Limit

BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::Lite.3 \
		Class::DBI::Lite::CacheManager.3 \
		Class::DBI::Lite::CacheManager::InMemory.3 \
		Class::DBI::Lite::CacheManager::Memcached.3 \
		Class::DBI::Lite::ColumnInfo.3 \
		Class::DBI::Lite::Fixture.3 \
		Class::DBI::Lite::Iterator.3 \
		Class::DBI::Lite::Pager.3 \
		Class::DBI::Lite::TableInfo.3 \
		Class::DBI::Lite::Tutorial.3

.include <bsd.port.mk>
