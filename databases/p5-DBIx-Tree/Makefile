PORTNAME=	DBIx-Tree
PORTVERSION=	1.98
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for generating a tree from a self-referential table

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=1.622:databases/p5-DBI
TEST_DEPENDS=	p5-DBD-SQLite>=1.37:databases/p5-DBD-SQLite

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
