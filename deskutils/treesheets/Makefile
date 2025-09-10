PORTNAME=	treesheets
DISTVERSION=	2507
CATEGORIES=	deskutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free form data organizer
WWW=		https://strlen.com/treesheets/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/ZLIB_LICENSE.txt

USES=		cmake desktop-file-utils shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	aardappel
USE_WX=		3.2
GH_TUPLE=	aardappel:lobster:v2025.3:external/lobster

PORTDATA=	images scripts
PORTDOCS=	docs readme-ko.html readme-zh_CN.html readme.html
PORTEXAMPLES=	examples

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools

post-extract:
	${MKDIR} ${WRKDIR}/.build/_deps/lobster-src
	${CP} -R ${WRKSRC}/lobster/* ${WRKDIR}/.build/_deps/lobster-src

.include <bsd.port.mk>
