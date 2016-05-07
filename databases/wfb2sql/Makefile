# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wfb2sql
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CIA World Fact Book to SQL Conversion Utility

BUILD_DEPENDS=	p5-Config-General>=0:devel/p5-Config-General
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
NO_BUILD=	yes

OPTION_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	bin/wfb2sql
PORTDOCS=	wfb2sql.html
PORTEXAMPLES=	wfb2sqlrc
SHEBANG_FILES=	wfb2sql

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wfb2sql ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wfb2sqlrc ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/wfb2sql.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
