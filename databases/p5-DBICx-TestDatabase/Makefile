# New ports collection makefile for:	DBICx-TestDatabase
# Date created:	   			23 Oct 2008
# Whom:		   			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBICx-TestDatabase
PORTVERSION=	0.04
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN/../../authors/id/J/JR/JROCKWAY/
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Module to create temporary database from a DBIx::Class::Schema

RUN_DEPENDS=	p5-DBD-SQLite>=1.12:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator
BUILD_DEPENDS=	p5-DBIx-Class>=0.07005:${PORTSDIR}/databases/p5-DBIx-Class

PERL_CONFIGURE=	yes

MAN3=		DBICx::TestDatabase.3 \
		DBICx::TestDatabase::Subclass.3

.include <bsd.port.mk>
