PORTNAME=	PHP_CodeCoverage
PORTVERSION=	12.3.3
CATEGORIES=	devel pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library that provides PHP code coverage information
WWW=		https://github.com/sebastianbergmann/php-code-coverage

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}File_Iterator>=0:devel/pear-File_Iterator@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}PHP_TokenStream>=01:devel/pear-PHP_TokenStream@${PHP_FLAVOR} \
		${PEAR_PKGNAMEPREFIX}Text_Template>=0:textproc/pear-Text_Template@${PHP_FLAVOR}

USES=		pear:env

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	php-code-coverage

OPTIONS_DEFINE=	DOM XDEBUG
DOM_DESC=	Enable DOM support
XDEBUG_DESC=	Enable Xdebug support

DOM_USE=	PHP=dom
DOM_USES=	php
XDEBUG_RUN_DEPENDS=	${PECL_PKGNAMEPREFIX}xdebug>=0:devel/pecl-xdebug@${PHP_FLAVOR}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
