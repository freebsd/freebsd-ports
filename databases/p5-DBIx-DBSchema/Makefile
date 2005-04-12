# New ports collection makefile for:	databases/p5-DBIx-DBSchema
# Date created:				21 September 2002
# Whom:					Peter Avalos <pavalos@theshell.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-DBSchema
PORTVERSION=	0.26
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	An OO-interface to database schemas

BUILD_DEPENDS=	${SITE_PERL}/FreezeThaw.pm:${PORTSDIR}/devel/p5-FreezeThaw
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::DBSchema.3 DBIx::DBSchema::ColGroup.3 \
	DBIx::DBSchema::ColGroup::Index.3 DBIx::DBSchema::ColGroup::Unique.3 \
	DBIx::DBSchema::Column.3 DBIx::DBSchema::DBD.3 \
	DBIx::DBSchema::DBD::mysql.3 DBIx::DBSchema::DBD::Pg.3 \
	DBIx::DBSchema::DBD::Sybase.3 DBIx::DBSchema::Table.3 \
	DBIx::DBSchema::DBD::Oracle.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif
.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
