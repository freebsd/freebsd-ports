# $FreeBSD$

PORTNAME=	lm4tools
PORTVERSION=	0.1.3.20141201
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	TI Tiva C ARM microcontroller tools

LICENSE=	GPLv2 BSD3CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	utzig
GH_TAGNAME=	5a4bc0b

USES=		pkgconfig gmake

PORTDOCS=	README.md \
		lmicdiusb/commands.txt lmicdiusb/README
PLIST_FILES=	bin/lm4flash bin/lmicdi

do-build:
	@${MAKE_CMD} -C ${WRKSRC}/lm4flash all
	@${MAKE_CMD} -C ${WRKSRC}/lmicdiusb all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lm4flash/lm4flash ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/lmicdiusb/lmicdi ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README.md
	${MKDIR} ${STAGEDIR}${DOCSDIR}/lmicdiusb
	${INSTALL_DATA} ${WRKSRC}/lmicdiusb/commands.txt ${STAGEDIR}${DOCSDIR}/lmicdiusb/commands.txt
	${INSTALL_DATA} ${WRKSRC}/lmicdiusb/README ${STAGEDIR}${DOCSDIR}/lmicdiusb/README

.include <bsd.port.mk>
