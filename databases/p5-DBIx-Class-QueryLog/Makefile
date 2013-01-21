# Created by: Andrey Kostenko <andrey@kostenko.name>
# $FreeBSD$

PORTNAME=	DBIx-Class-QueryLog
PORTVERSION=	1.3.3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log queries for later analysis

BUILD_DEPENDS=	p5-DBIx-Class>=0.07000:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DBIx::Class::QueryLog.3 \
		DBIx::Class::QueryLog::Analyzer.3 \
		DBIx::Class::QueryLog::Query.3 \
		DBIx::Class::QueryLog::Transaction.3

.include <bsd.port.mk>
