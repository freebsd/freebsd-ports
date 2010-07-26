# New ports collection makefile for: python-daemon
# Date created: 7 Jul 2010
# Whom:			jessekempf@gmail.com
# $FreeBSD$
#

PORTNAME=	lamson
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Python mail server built like a web application server

BUILD_DEPENDS=\
	${PYTHON_PKGNAMEPREFIX}Jinja2>0:${PORTSDIR}/devel/py-Jinja2\
	${PYTHON_PKGNAMEPREFIX}chardet>0:${PORTSDIR}/textproc/py-chardet\
	${PYTHON_PKGNAMEPREFIX}daemon>0:${PORTSDIR}/devel/py-daemon\
	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock\
	${PYTHON_PKGNAMEPREFIX}nose>0:${PORTSDIR}/devel/py-nose\
	${PYTHON_PKGNAMEPREFIX}lockfile>0:${PORTSDIR}/devel/py-lockfile

BROKEN=		leaves behind files on deinstall

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes

PLIST_SUB=\
	PY_VERS=${PYTHON_VERSION:S/^python//}

.include <bsd.port.mk>
