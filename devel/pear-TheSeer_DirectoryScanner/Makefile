PORTNAME=	DirectoryScanner
PORTVERSION=	1.3.3
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}TheSeer_

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Recursive directory scanner and filter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear:env
USE_PHP=	fileinfo

NO_ARCH=	yes
NO_BUILD=	yes
PEAR_CHANNEL=	theseer
PEAR_CHANNEL_VER=	>=20120501

PLIST_FILES=	share/PHP/DirectoryScanner/directoryscanner.php

USE_GITHUB=	yes
GH_ACCOUNT=	theseer

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/PHP/DirectoryScanner
	${INSTALL_SCRIPT} ${WRKSRC}/src/directoryscanner.php ${STAGEDIR}${PREFIX}/share/PHP/DirectoryScanner

.include <bsd.port.mk>
