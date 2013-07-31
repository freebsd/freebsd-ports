# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Text-Query-SQL
PORTVERSION=	0.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Text-Query-SQL provides query builders for SQL databases

BUILD_DEPENDS=	p5-Text-Query>=0:${PORTSDIR}/textproc/p5-Text-Query
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

USES=		perl5
USE_PERL5=	configure patch

MAN3=		Text::Query::BuildSQLMifluz.3 Text::Query::BuildSQLMySQL.3 \
		Text::Query::BuildSQLFulcrum.3 Text::Query::BuildSQL.3 \
		Text::Query::BuildSQLPg.3 Text::Query::SolveSQL.3 \
		Bundle::Text::Query::BuildSQL.3

pre-patch:
	@${PERL} -pi -e '/DBI/ and $$_=""' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
