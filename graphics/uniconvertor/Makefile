# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	uniconvertor
PORTVERSION=	1.1.5
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Universal vector graphics translator

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sk1libs/__init__.py:graphics/sk1libs

USES=		python
USE_PYTHON=	distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/uniconvertor/app/modules/*.so

.include <bsd.port.mk>
