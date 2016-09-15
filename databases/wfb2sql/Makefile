# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wfb2sql
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CIA World Fact Book to SQL Conversion Utility

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Config-General>=0:devel/p5-Config-General
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	wfb2sql
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/wfb2sql
PORTDOCS=	wfb2sql.html
PORTEXAMPLES=	wfb2sqlrc

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wfb2sql ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wfb2sqlrc ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/wfb2sql.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
