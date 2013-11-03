# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-NoSQL
PORTVERSION=	0.0020
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	NoSQL-ish overlay for an SQL database

BUILD_DEPENDS=	p5-Any-Moose>0:${PORTSDIR}/devel/p5-Any-Moose \
		p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Hash-Merge-Simple>0:${PORTSDIR}/devel/p5-Hash-Merge-Simple \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
		p5-SQL-Translator>0:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-DBIx-Class>=0.08124:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
