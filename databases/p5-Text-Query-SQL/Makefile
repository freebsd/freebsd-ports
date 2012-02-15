# New ports collection makefile for:	databases/p5-Text-Query-SQL
# Date created:				31 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Query-SQL
PORTVERSION=	0.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Text-Query-SQL provides query builders for SQL databases

BUILD_DEPENDS=	${SITE_PERL}/Text/Query.pm:${PORTSDIR}/textproc/p5-Text-Query
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI

PERL_CONFIGURE=	yes

MAN3=		Text::Query::BuildSQLMifluz.3 Text::Query::BuildSQLMySQL.3 \
		Text::Query::BuildSQLFulcrum.3 Text::Query::BuildSQL.3 \
		Text::Query::BuildSQLPg.3 Text::Query::SolveSQL.3 \
		Bundle::Text::Query::BuildSQL.3

pre-patch:
	@${PERL} -pi -e '/DBI/ and $$_=""' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
