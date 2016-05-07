# Created by: Neal Nelson <neal@nelson.name>
# $FreeBSD$

PORTNAME=	twistedCore
PORTVERSION=	15.2.1
CATEGORIES=	devel net python
MASTER_SITES=	http://twistedmatrix.com/Releases/Core/${PORTVERSION:R}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedCore-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Asynchronous networking framework for Python (Core Module)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.0:devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	VERIFY
OPTIONS_DEFAULT=VERIFY

VERIFY_DESC=		Server (SNI) and Service Verification Support (RFC6125+)
VERIFY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}service_identity>=0:security/py-service_identity

# - Note that Twisted ships with some graphical examples and clients that
#   require PyGNOME to run.  These are not central to the functioning of
#   Twisted, but the user should feel free to install x11-toolits/py-gnome2
#   separately if desired.

USE_PYTHON=	autoplist distutils
USES=		python:2 tar:bzip2

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/python/sendmsg.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/twisted/test/raiser.so

.include <bsd.port.mk>
