# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	pudb
PORTVERSION=	0.93.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gslin@gslin.org
COMMENT=	A full-screen, console-based Python debugger

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}urwid>0:${PORTSDIR}/devel/py-urwid

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
