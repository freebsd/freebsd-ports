# $FreeBSD$

PORTNAME=	DBIx-Class-Fixtures
PORTVERSION=	1.001032
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SKAUFMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to use fixtures with DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Accessor-Grouped>=0.1001:devel/p5-Class-Accessor-Grouped \
	p5-Config-Any>=0.23:devel/p5-Config-Any \
	p5-DBIx-Class>=0.08102:databases/p5-DBIx-Class \
	p5-DBIx-Class-Schema-Loader>=0.07035:databases/p5-DBIx-Class-Schema-Loader \
	p5-Data-Dump-Streamer>=2.05:devel/p5-Data-Dump-Streamer \
	p5-Data-Visitor>=0.3:devel/p5-Data-Visitor \
	p5-DateTime>=1.03:devel/p5-DateTime \
	p5-DateTime-Format-MySQL>0:devel/p5-DateTime-Format-MySQL \
	p5-DateTime-Format-Pg>0:devel/p5-DateTime-Format-Pg \
	p5-DateTime-Format-SQLite>=0.1:devel/p5-DateTime-Format-SQLite \
	p5-File-Copy-Recursive>=0.38:devel/p5-File-Copy-Recursive \
	p5-Hash-Merge>=0.1:textproc/p5-Hash-Merge \
	p5-IO-All>=0.85:devel/p5-IO-All \
	p5-YAML-Syck>=1.27:textproc/p5-YAML-Syck \
	p5-Path-Class>=0.32:devel/p5-Path-Class
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-DBD-SQLite>=1.12:databases/p5-DBD-SQLite \
	p5-DBIx-Class-InflateColumn-FS>=0.01007:databases/p5-DBIx-Class-InflateColumn-FS \
	p5-Test-Compile>0:devel/p5-Test-Compile \
	p5-Test-TempDir-Tiny>0:devel/p5-Test-TempDir-Tiny

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
