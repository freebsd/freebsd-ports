PORTNAME=	PHPLOC
PORTVERSION=	7.0.2
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for quickly measuring the size of a PHP project
WWW=		https://github.com/sebastianbergmann/phploc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_FinderFacade>=0:devel/pear-SebastianBergmann_FinderFacade@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}SebastianBergmann_Git>=0:devel/pear-SebastianBergmann_Git@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}SebastianBergmann_Version>=0:devel/pear-SebastianBergmann_Version@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Symfony_Component_Console>=0:devel/pear-Symfony_Component_Console@${PHP_FLAVOR}

USES=		pear:env

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	phploc

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
