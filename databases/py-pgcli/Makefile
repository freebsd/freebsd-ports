# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pgcli
PORTVERSION=	0.20.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI for Postgres Database with auto-completion and syntax highlighting

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=4.1:${PORTSDIR}/devel/py-click \
		${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}pgspecial>=1.1.0:${PORTSDIR}/databases/py-pgspecial \
		${PYTHON_PKGNAMEPREFIX}prompt_toolkit>=0.46:${PORTSDIR}/devel/py-prompt_toolkit \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.5.4:${PORTSDIR}/databases/py-psycopg2 \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.9:${PORTSDIR}/devel/py-setproctitle \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.1.16:${PORTSDIR}/databases/py-sqlparse

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		pgsql python

.include <bsd.port.mk>
