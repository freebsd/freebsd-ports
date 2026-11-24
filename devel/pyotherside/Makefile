PORTNAME=	pyotherside
DISTVERSION=	1.6.2
CATEGORIES=	devel

MAINTAINER=	daniel@shafer.cc
COMMENT=	Asynchronous Python 3 Bindings for Qt 6
WWW=		https://thp.io/2011/pyotherside/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gettext-runtime gl python qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	thp

USE_GL=		gl opengl
USE_QT=		base declarative svg

QMAKE_ARGS=	PYTHON_CONFIG=${PYTHON_CMD}-config

TEST_ENV=	QT_QPA_PLATFORM=offscreen

do-test:
	@(cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ./tests)

.include <bsd.port.mk>
