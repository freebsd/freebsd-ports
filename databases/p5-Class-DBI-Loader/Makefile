# Created by: mat
# $FreeBSD$

PORTNAME=	Class-DBI-Loader
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dynamic definition of Class::DBI sub classes

RUN_DEPENDS=	p5-Class-DBI>=0.89:${PORTSDIR}/databases/p5-Class-DBI \
		p5-DBI>=1.3:${PORTSDIR}/databases/p5-DBI \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::DBI::Loader.3 \
		Class::DBI::Loader::Generic.3 \
		Class::DBI::Loader::Pg.3 \
		Class::DBI::Loader::SQLite.3 \
		Class::DBI::Loader::mysql.3

OPTIONS_DEFINE=	PGSQL MYSQL SQLITE DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-Class-DBI-Pg>=0:${PORTSDIR}/databases/p5-Class-DBI-Pg
.endif
.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-Class-DBI-mysql>=0:${PORTSDIR}/databases/p5-Class-DBI-mysql
.endif
.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	p5-Class-DBI-SQLite>=0:${PORTSDIR}/databases/p5-Class-DBI-SQLite
.endif

.include <bsd.port.mk>
