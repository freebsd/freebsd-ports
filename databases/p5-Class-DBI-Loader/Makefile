# New ports collection makefile for:	p5-Class-DBI-Loader
# Date created:	   21 july 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Loader
PORTVERSION=	0.34
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dynamic definition of Class::DBI sub classes

BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-Test-Simple>=0.32:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	p5-Class-DBI>=0.89:${PORTSDIR}/databases/p5-Class-DBI \
		p5-DBI>=1.30:${PORTSDIR}/databases/p5-DBI \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::Loader.3 \
		Class::DBI::Loader::Generic.3 \
		Class::DBI::Loader::Pg.3 \
		Class::DBI::Loader::SQLite.3 \
		Class::DBI::Loader::mysql.3

.if !defined(NOPORTDOCS)
DOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

OPTIONS=	PGSQL "Enable support for PostgreSQL" Off \
		MYSQL "Enable support for MySQL" Off \
		SQLITE "Enable support for SQLite" Off

.include <bsd.port.pre.mk>

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${SITE_PERL}/Class/DBI/Pg.pm:${PORTSDIR}/databases/p5-Class-DBI-Pg
.endif
.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/Class/DBI/mysql.pm:${PORTSDIR}/databases/p5-Class-DBI-mysql
.endif
.if defined(WITH_SQLITE)
RUN_DEPENDS+=	${SITE_PERL}/Class/DBI/SQLite.pm:${PORTSDIR}/databases/p5-Class-DBI-SQLite
.endif

.include <bsd.port.post.mk>
