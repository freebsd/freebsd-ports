# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	mysqlreport
PORTVERSION=	3.5
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/scripts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mysqlreport makes a friendly report of important MySQL status values

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

USES=		perl5 shebangfix tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/mysqlreport
PORTDOCS=	COPYING mysqlreportguide.html mysqlreportdoc.html

SHEBANG_FILES=	mysqlreport

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mysqlreport ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
