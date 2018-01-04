# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	uniconvertor
PORTVERSION=	1.1.5
CATEGORIES=	graphics python
MASTER_SITES=	https://downloads.sk1project.net/uniconvertor/v1.1.5/ \
		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/uniconvertor/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Universal vector graphics translator

LICENSE=	LGPL20+ GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/src/GNU_GPL_v2
LICENSE_FILE_LGPL20+ =	${WRKSRC}/src/GNU_LGPL_v2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sk1libs/__init__.py:graphics/sk1libs@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/uniconvertor/app/modules/*.so

.include <bsd.port.mk>
