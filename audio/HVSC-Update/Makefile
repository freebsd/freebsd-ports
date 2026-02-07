PORTNAME=	HVSC-Update
DISTVERSION=	2.8.8
CATEGORIES=	audio emulators

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Update program for the HVSC C= 64 SID tune collection
WWW=		https://github.com/laustbn/hvsc-update-tool

USES=		cmake compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	laustbn
GH_PROJECT=	hvsc-update-tool
GH_TAGNAME=	ff21266

PORTDOCS=	HVS_file_format.txt HVSC_Update.txt SID_file_format.txt
PLIST_FILES=	bin/hvsc_update_tool

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/hvsc_update_tool ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
