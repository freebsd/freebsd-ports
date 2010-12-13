# New ports collection makefile for:	p5-DBIx-NoSQL
# Date created:				Dec 07, 2010
# Whom:	      				Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-NoSQL
PORTVERSION=	0.0015
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	NoSQL-ish overlay for an SQL database

RUN_DEPENDS=	p5-Any-Moose>0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Hash-Merge-Simple>0:${PORTSDIR}/devel/p5-Hash-Merge-Simple \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
		p5-SQL-Translator>0:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-DBIx-Class>=0.08124:${PORTSDIR}/databases/p5-DBIx-Class

PERL_CONFIGURE=	yes

MAN3=		DBIx::NoSQL.3 \
		DBIx::NoSQLite.3

.include <bsd.port.mk>
