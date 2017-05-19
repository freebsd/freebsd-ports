# $FreeBSD$

PORTNAME=	PyExecJS
PORTVERSION=	1.4.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Run JavaScript code from Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python zip
USE_PYTHON=     distutils autoplist

OPTIONS_GROUP=		RUNTIME
OPTIONS_GROUP_RUNTIME=	NODE SPIDERMONKEY PHANTOMJS
NODE_DESC=		Use www/node as JavaScript backend
NODE_RUN_DEPENDS=	node>=0.8.0:www/node
SPIDERMONKEY_DESC=	Use lang/spidermonkey24 as JavaScript backend
SPIDERMONKEY_RUN_DEPENDS=	js:lang/spidermonkey24
PHANTOMJS_DESC=		Use lang/phantomjs as JavaScript backend
PHANTOMJS_RUN_DEPENDS=	phantomjs:lang/phantomjs
OPTIONS_DEFAULT=	NODE

.include <bsd.port.mk>
