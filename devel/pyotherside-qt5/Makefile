PORTNAME=	pyotherside
DISTVERSION=	1.5.9
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	-qt5

MAINTAINER=	daniel@shafer.cc
COMMENT=	Asynchronous Python 3 Bindings for Qt 5
WWW=		https://thp.io/2011/pyotherside/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gettext-runtime gl python qmake qt:5
USE_QT=		core declarative declarative-test gui network quickcontrols \
		svg testlib widgets buildtools:build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	thp

QMAKE_ARGS=	PYTHON_CONFIG=${PYTHON_CMD}-config

.include <bsd.port.mk>
