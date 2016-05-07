# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	mysqlreport
PORTVERSION=	3.5
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mysqlreport makes a friendly report of important MySQL status values

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-DBI>=0:databases/p5-DBI \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

NO_ARCH=	yes
NO_BUILD=	yes
USES=		perl5 shebangfix
WRKSRC_SUBDIR=	${PORTNAME}

PLIST_FILES=	bin/mysqlreport
PORTDOCS=	COPYING mysqlreportguide.html mysqlreportdoc.html

USE_GITHUB=	yes
GH_ACCOUNT=	daniel-nichter
GH_PROJECT=	hackmysql.com
GH_TAGNAME=	f0f327b

SHEBANG_FILES=	mysqlreport

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mysqlreport ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
