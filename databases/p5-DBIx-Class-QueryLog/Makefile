# New ports collection makefile for:	Log-Dispatch-Configurator-YAML
# Date created:				28 May 2008
# Whom:					Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-QueryLog
PORTVERSION=	1.1.5
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Log queries for later analysis

RUN_DEPENDS=	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class	\
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DBIx::Class::QueryLog.3 DBIx::Class::QueryLog::Query.3 DBIx::Class::QueryLog::Transaction.3 DBIx::Class::QueryLog::Analyzer.3

.include <bsd.port.mk>
