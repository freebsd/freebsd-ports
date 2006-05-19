# New ports collection makefile for:	p5-Class-DBI-Loader
# Date created:	   21 july 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-Loader
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Dynamic definition of Class::DBI sub classes

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/Lingua/EN/Inflect.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::Loader.3 \
		Class::DBI::Loader::Generic.3 \
		Class::DBI::Loader::Pg.3 \
		Class::DBI::Loader::SQLite.3 \
		Class::DBI::Loader::mysql.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

OPTIONS=	PGSQL "Enable support for PostgreSQL" Off \
		MYSQL "Enable support for MySQL" Off \
		SQLITE "Enable support for SQLite" Off

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or higher. Please install lang/perl5.8 and try again
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=  ${SITE_PERL}/Class/DBI/Pg.pm:${PORTSDIR}/databases/p5-Class-DBI-Pg
.endif
.if defined(WITH_MYSQL)
RUN_DEPENDS+=  ${SITE_PERL}/Class/DBI/mysql.pm:${PORTSDIR}/databases/p5-Class-DBI-mysql
.endif
.if defined(WITH_SQLITE)
RUN_DEPENDS+=  ${SITE_PERL}/Class/DBI/SQLite.pm:${PORTSDIR}/databases/p5-Class-DBI-SQLite
.endif

.include <bsd.port.post.mk>
