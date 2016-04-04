# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-DBIx-Class
PORTVERSION=	0.47
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easier test cases for your DBIx::Class applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Any>=0.19:devel/p5-Config-Any \
		p5-DBIx-Class>=0.08123:databases/p5-DBIx-Class \
		p5-DBIx-Class-Schema-PopulateMore>=0.16:databases/p5-DBIx-Class-Schema-PopulateMore \
		p5-DBIx-Class-TimeStamp>=0.13:databases/p5-DBIx-Class-TimeStamp \
		p5-DBIx-Class-UUIDColumns>=0.02005:databases/p5-DBIx-Class-UUIDColumns \
		p5-Data-UUID>=1.215:devel/p5-Data-UUID \
		p5-Data-Visitor>=0.27:devel/p5-Data-Visitor \
		p5-Hash-Merge>=0.11:textproc/p5-Hash-Merge \
		p5-List-MoreUtils>=0.22:lang/p5-List-MoreUtils \
		p5-Module-Runtime>=0.013:devel/p5-Module-Runtime \
		p5-Moose>=1.10:devel/p5-Moose \
		p5-MooseX-Attribute-ENV>=0.01:devel/p5-MooseX-Attribute-ENV \
		p5-MooseX-Types>=0.23:devel/p5-MooseX-Types \
		p5-Path-Class>=0.21:devel/p5-Path-Class \
		p5-SQL-Translator>=0.11006:databases/p5-SQL-Translator \
		p5-Sub-Exporter>=0.982:devel/p5-Sub-Exporter \
		p5-Test-Deep>=0.106:devel/p5-Test-Deep
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-Types-LoadableClass>=0:devel/p5-MooseX-Types-LoadableClass \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-mysqld>=0:databases/p5-Test-mysqld \
		p5-Test-postgresql>=0:databases/p5-Test-postgresql
# Also for test:
#USE_MYSQL+=	server

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
