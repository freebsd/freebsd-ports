# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	pudb
PORTVERSION=	2014.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Full-screen, console-based Python debugger

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.1.1:${PORTSDIR}/devel/py-urwid

PYTHON_FEATURES=autoplist,distutils
USES=		python

.include <bsd.port.mk>
