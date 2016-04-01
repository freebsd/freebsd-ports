# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	Class-DBI-SQLite
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extension to Class::DBI for sqlite

RUN_DEPENDS=	p5-Ima-DBI>=0:databases/p5-Ima-DBI \
		p5-Class-DBI>=0:databases/p5-Class-DBI \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-SQL-Statement>=0:databases/p5-SQL-Statement \
		p5-Clone>=0:devel/p5-Clone
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	Changes

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
