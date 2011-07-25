# New ports collection makefile for:	Log-Dispatch-Configurator-YAML
# Date created:				28 May 2008
# Whom:					Andrey Kostenko <andrey@kostenko.name>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-QueryLog
PORTVERSION=	1.3.1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log queries for later analysis

RUN_DEPENDS=	p5-DBIx-Class>=0.07000:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose

PERL_CONFIGURE=	yes

MAN3=		DBIx::Class::QueryLog.3 \
		DBIx::Class::QueryLog::Analyzer.3 \
		DBIx::Class::QueryLog::Query.3 \
		DBIx::Class::QueryLog::Transaction.3

.include <bsd.port.mk>
