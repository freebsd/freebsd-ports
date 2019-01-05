# Created by: mat
# $FreeBSD$

PORTNAME=	Class-DBI-Loader
PORTVERSION=	0.34
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dynamic definition of Class::DBI sub classes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-DBI>=0.89:databases/p5-Class-DBI \
		p5-DBI>=1.3:databases/p5-DBI \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=	PGSQL MYSQL SQLITE DOCS

MYSQL_RUN_DEPENDS=	p5-Class-DBI-mysql>=0:databases/p5-Class-DBI-mysql
PGSQL_RUN_DEPENDS=	p5-Class-DBI-Pg>=0:databases/p5-Class-DBI-Pg
SQLITE_RUN_DEPENDS=	p5-Class-DBI-SQLite>=0:databases/p5-Class-DBI-SQLite

PORTDOCS=	Changes README

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
