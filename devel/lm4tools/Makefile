# $FreeBSD$

PORTNAME=	lm4tools
PORTVERSION=	0.1.3.20160905
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	TI Tiva C ARM microcontroller tools

LICENSE=	GPLv2 BSD3CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	utzig
GH_TAGNAME=	65fbc45

USES=		gmake

PORTDOCS=	*
PLIST_FILES=	bin/lm4flash bin/lmicdi

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lm4flash/lm4flash ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/lmicdiusb/lmicdi ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README.md
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/lmicdiusb
	${INSTALL_DATA} ${WRKSRC}/lmicdiusb/commands.txt ${STAGEDIR}${DOCSDIR}/lmicdiusb/commands.txt
	${INSTALL_DATA} ${WRKSRC}/lmicdiusb/README ${STAGEDIR}${DOCSDIR}/lmicdiusb/README

.include <bsd.port.mk>
