# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mysqltuner
PORTVERSION=	1.7.17
CATEGORIES=	databases

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Assist you with MySQL Configuration

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

USES=		perl5 shebangfix
NO_ARCH=	yes
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	major
GH_PROJECT=	MySQLTuner-perl

PLIST_FILES=	bin/${PORTNAME}

SHEBANG_FILES=	${PORTNAME}.pl

PORTDOCS=	CONTRIBUTING INTERNALS README USAGE

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc}.md ${STAGEDIR}${DOCSDIR}/${doc}
.endfor

.include <bsd.port.mk>
