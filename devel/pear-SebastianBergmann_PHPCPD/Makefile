PORTNAME=	PHPCPD
PORTVERSION=	6.0.3
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Copy/Paste Detector (CPD) for PHP code
WWW=		https://github.com/sebastianbergmann/phpcpd

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}PHP_Timer>=0:devel/pear-PHP_Timer@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}SebastianBergmann_FinderFacade>=0:devel/pear-SebastianBergmann_FinderFacade@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}ezc_ConsoleTools>=0:devel/pear-ezc_ConsoleTools@${PHP_FLAVOR}

USES=		pear:env
USE_PHP=	tokenizer

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	phpcpd

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
