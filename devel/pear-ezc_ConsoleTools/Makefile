PORTNAME=	ConsoleTools
PORTVERSION=	1.6.1
CATEGORIES=	devel pear
MASTER_SITES=	http://components.ez.no/get/
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}${PEAR_CHANNEL}_

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of classes to do different actions with the console
WWW=		https://ezcomponents.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PEAR_PKGNAMEPREFIX}ezc_Base>=1.8:devel/pear-ezc_Base@${PHP_FLAVOR}
RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}ezc_Base>=1.8:devel/pear-ezc_Base@${PHP_FLAVOR}

USES=		pear

NO_ARCH=	yes
PEAR_CHANNEL=	ezc

.include <bsd.port.mk>
