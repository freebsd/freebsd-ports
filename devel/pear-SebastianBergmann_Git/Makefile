PORTNAME=	Git
PORTVERSION=	2.1.4
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple PHP wrapper for Git
WWW=		https://github.com/sebastianbergmann/git

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear:env

NO_ARCH=	yes
NO_BUILD=	yes

PORTDATA=	Exception/Exception.php \
		Exception/RuntimeException.php \
		Git.php

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	git

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
