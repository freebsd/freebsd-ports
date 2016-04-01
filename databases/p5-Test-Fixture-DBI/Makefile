# $FreeBSD$

PORTNAME=	Test-Fixture-DBI
PORTVERSION=	0.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to load fixture data into database

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-DBI>0:databases/p5-DBI \
	p5-SQL-Abstract>0:databases/p5-SQL-Abstract \
	p5-SQL-Abstract-Plugin-InsertMulti>0:databases/p5-SQL-Abstract-Plugin-InsertMulti \
	p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require \
	p5-YAML-Syck>0:textproc/p5-YAML-Syck
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Sub-Uplevel>=0:devel/p5-Sub-Uplevel

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
