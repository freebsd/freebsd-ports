# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mysqltuner
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Assist you with MySQL Configuration

LICENSE=	GPLv3

USES=		perl5 shebangfix
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	major
GH_PROJECT=	MySQLTuner-perl

WRKSRC=		${WRKDIR}/MySQLTuner-perl-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}

SHEBANG_FILES=	${PORTNAME}.pl

PORTDOCS=	README

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,}.md ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
