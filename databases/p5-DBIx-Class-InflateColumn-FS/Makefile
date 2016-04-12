# $FreeBSD$

PORTNAME=	DBIx-Class-InflateColumn-FS
PORTVERSION=	0.01007
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to {in,de}flate columns to Path::Class::File objects

RUN_DEPENDS=	\
	p5-DBIx-Class>=0.08:databases/p5-DBIx-Class \
	p5-DBIx-Class-UUIDColumns>=0.02005:databases/p5-DBIx-Class-UUIDColumns \
	p5-Path-Class>0:devel/p5-Path-Class
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-DBICx-TestDatabase>=0:databases/p5-DBICx-TestDatabase

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
