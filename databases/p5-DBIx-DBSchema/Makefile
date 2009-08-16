# New ports collection makefile for:	databases/p5-DBIx-DBSchema
# Date created:				21 September 2002
# Whom:					Peter Avalos <pavalos@theshell.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-DBSchema
PORTVERSION=	0.36
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An OO-interface to database schemas

BUILD_DEPENDS=	${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::DBSchema.3 DBIx::DBSchema::ColGroup.3 \
	DBIx::DBSchema::ColGroup::Index.3 DBIx::DBSchema::ColGroup::Unique.3 \
	DBIx::DBSchema::Column.3 DBIx::DBSchema::DBD.3 \
	DBIx::DBSchema::DBD::mysql.3 DBIx::DBSchema::DBD::Pg.3 \
	DBIx::DBSchema::DBD::Sybase.3 DBIx::DBSchema::Table.3 \
	DBIx::DBSchema::DBD::Oracle.3 DBIx::DBSchema::DBD::SQLite.3 \
	DBIx::DBSchema::Index.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
