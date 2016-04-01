# $FreeBSD$

PORTNAME=	DBIx-DBHResolver
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to resolve DB connection with many database servers

RUN_DEPENDS=	\
	p5-Class-Accessor>0:devel/p5-Class-Accessor \
	p5-Config-Any>0:devel/p5-Config-Any \
	p5-DBI>0:databases/p5-DBI \
	p5-Data-Util>0:devel/p5-Data-Util \
	p5-Hash-Merge-Simple>0:devel/p5-Hash-Merge-Simple \
	p5-Try-Tiny>0:lang/p5-Try-Tiny \
	p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require \
	p5-YAML>0:textproc/p5-YAML
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-DBD-SQLite>0:databases/p5-DBD-SQLite \
		p5-Sub-Uplevel>=0:devel/p5-Sub-Uplevel
# TODO: fix test.

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
