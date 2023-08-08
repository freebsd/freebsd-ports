PORTNAME=	imgkit
PORTVERSION=	1.2.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Python wrapper to convert html to image
WWW=		https://github.com/jarrekk/imgkit

LICENSE=	MIT

USES=		python
USE_PYTHON=	distutils autoplist

RUN_DEPENDS+=	wkhtmltopdf>0:converters/wkhtmltopdf

.include <bsd.port.mk>
