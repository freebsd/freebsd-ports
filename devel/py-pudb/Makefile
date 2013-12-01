# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	pudb
PORTVERSION=	2013.3.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Full-screen, console-based Python debugger

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}urwid>0:${PORTSDIR}/devel/py-urwid

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
