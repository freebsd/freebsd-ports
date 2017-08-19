# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-NoSQL
PORTVERSION=	0.0021
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	NoSQL-ish overlay for an SQL database

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-DBD-SQLite>=1.44:databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.08124:databases/p5-DBIx-Class \
		p5-Data-GUID>=0:devel/p5-Data-GUID \
		p5-Hash-Merge-Simple>=0:devel/p5-Hash-Merge-Simple \
		p5-Hash-Merge-Simple>=0:devel/p5-Hash-Merge-Simple \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-JSON>=0:converters/p5-JSON \
		p5-Moose>=0:devel/p5-Moose \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-SQL-Translator>=0.11016:databases/p5-SQL-Translator \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Most>=0:devel/p5-Test-Most

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
