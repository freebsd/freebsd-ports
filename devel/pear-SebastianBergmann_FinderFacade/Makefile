PORTNAME=	FinderFacade
PORTVERSION=	2.0.0
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convenience wrapper for Symfony Finder component
WWW=		https://github.com/sebastianbergmann/finder-facade

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Symfony_Component_Finder>=0:devel/pear-Symfony_Component_Finder@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}TheSeer_fDOMDocument>=0:devel/pear-TheSeer_fDOMDocument@${PHP_FLAVOR}

USES=		pear:env

NO_ARCH=	yes
NO_BUILD=	yes

PORTDATA=	Configuration.php \
		FinderFacade.php

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	finder-facade

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
