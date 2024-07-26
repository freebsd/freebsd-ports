PORTNAME=	treesheets
DISTVERSION=	1.0.20240629
CATEGORIES=	deskutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Free form data organizer
WWW=		https://strlen.com/treesheets/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/ZLIB_LICENSE.txt

USES=		cmake desktop-file-utils shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	aardappel
#GH_TAGNAME=	>= 9850843724 fails to build: https://github.com/aardappel/treesheets/issues/686
GH_TAGNAME=	9723493654
USE_WX=		3.2

PORTSCOUT=	ignore:1 # upstream uses CI run ids as releases

PORTDATA=	images scripts
PORTDOCS=	docs readme.html
PORTEXAMPLES=	examples

OPTIONS_DEFINE=	DOCS EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools

.include <bsd.port.mk>
