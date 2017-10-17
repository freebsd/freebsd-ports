# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBICx-TestDatabase
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module to create temporary database from a DBIx::Class::Schema

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBD-SQLite>=1.29:databases/p5-DBD-SQLite \
		p5-SQL-Translator>=0:databases/p5-SQL-Translator
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBIx-Class>=0.07005:databases/p5-DBIx-Class

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
