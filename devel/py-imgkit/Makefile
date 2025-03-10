PORTNAME=	imgkit
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Python wrapper to convert html to image
WWW=		https://github.com/jarrekk/imgkit

LICENSE=	MIT

DEPRECATED=	Depends on expired converters/wkhtmltopdf
EXPIRATION_DATE=2025-03-31

USES=		python
USE_PYTHON=	distutils autoplist

RUN_DEPENDS+=	wkhtmltopdf>0:converters/wkhtmltopdf

.include <bsd.port.mk>
