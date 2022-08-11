PORTNAME=	fDOMDocument
PORTVERSION=	1.6.7
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}TheSeer_

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extension to PHP standard DOM

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear:env
USE_PHP=	dom xml

USE_GITHUB=	yes
GH_ACCOUNT=	theseer

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	share/PHP/fDOMDocument/fDOMDocument.php

PEAR_CHANNEL=	theseer
PEAR_CHANNEL_VER=	>=20120501

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/PHP/fDOMDocument
	${INSTALL_SCRIPT} ${WRKSRC}/src/fDOMDocument.php ${STAGEDIR}${PREFIX}/share/PHP/fDOMDocument

.include <bsd.port.mk>
