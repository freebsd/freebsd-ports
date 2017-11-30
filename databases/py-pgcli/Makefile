# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pgcli
PORTVERSION=	1.8.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI for Postgres Database with auto-completion and syntax highlighting

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cli-helpers>=0.2.3:devel/py-cli-helpers@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=4.1:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanize>=0.5.1:devel/py-humanize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pgspecial>=1.8.0:databases/py-pgspecial@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit>=1.0.10:devel/py-prompt_toolkit@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.4:databases/py-psycopg2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:textproc/py-pygments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.9:devel/py-setproctitle@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.2:databases/py-sqlparse@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		pgsql python

.include <bsd.port.mk>
