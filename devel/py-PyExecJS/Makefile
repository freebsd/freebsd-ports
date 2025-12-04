PORTNAME=	PyExecJS
DISTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Run JavaScript code from Python
WWW=		https://pypi.org/project/PyExecJS/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_GROUP=		RUNTIME
OPTIONS_GROUP_RUNTIME=	NODE SPIDERMONKEY
NODE_DESC=		Use www/node as JavaScript backend
NODE_RUN_DEPENDS=	node>=0.8.0:www/node
SPIDERMONKEY_DESC=	Use lang/spidermonkey52 as JavaScript backend
SPIDERMONKEY_RUN_DEPENDS=	js52:lang/spidermonkey52
OPTIONS_DEFAULT=	NODE

.include <bsd.port.mk>
