# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	DBIx-SearchBuilder
PORTVERSION=	1.66
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	michelle@sorbs.net
COMMENT=	Perl extension for easy SQL SELECT Statement generation

BUILD_DEPENDS=	p5-Class-ReturnValue>=0:devel/p5-Class-ReturnValue \
		p5-Cache-Simple-TimedExpiry>=0:devel/p5-Cache-Simple-TimedExpiry \
		p5-Want>=0:devel/p5-Want \
		p5-capitalization>=0:devel/p5-capitalization \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBIx-DBSchema>=0:databases/p5-DBIx-DBSchema \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Clone>=0:devel/p5-Clone \
		p5-Encode>=0:converters/p5-Encode
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_PERL5=	configure

post-patch:
		${CP} ${WRKSRC}/lib/DBIx/SearchBuilder/Handle/Pg.pm ${WRKSRC}/lib/DBIx/SearchBuilder/Handle/Pg32.pm
		${REINPLACE_CMD} -e 's/Pg/Pg32/g' ${WRKSRC}/lib/DBIx/SearchBuilder/Handle/Pg32.pm

.include <bsd.port.mk>
