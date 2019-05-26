# $FreeBSD$

PORTNAME=	bitcoinnodestats
DISTVERSION=	g20171121
PORTREVISION=	1
CATEGORIES=	finance python

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Basic Bitcoin node status and statistics web application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=2017.3:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-bitcoinlib>=0.8.0:finance/py-python-bitcoinlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django111>=1.11.7:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-bootstrap3>=9.1.0:www/py-django-bootstrap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-cron>=0.5.0:www/py-django-cron@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-debug-toolbar>=0:www/py-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonfield>=2.0.2:www/py-jsonfield@${PY_FLAVOR}

USES=		python:3.3+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	bartromgens
GH_TAGNAME=	5e8772d

NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	create_local_settings.py manage.py

SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} PYTHON_VER=${PYTHON_VER}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for _file in ${SHEBANG_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${_file} ${STAGEDIR}${DATADIR}
.endfor

.for _dir in bitcoinnodestats nodedata
	(cd ${WRKSRC}/${_dir} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${_dir} "! -name '*.bak'")
.endfor

.include <bsd.port.mk>
