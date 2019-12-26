# $FreeBSD$

PORTNAME=	vnc2flv
PORTVERSION=	20100207
PORTREVISION=	2
CATEGORIES=	deskutils multimedia www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Captures a VNC desktop session and saves as a flv

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

USES=		python:2.7
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	X11
X11_RUN_DEPENDS=x11vnc:net/x11vnc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/flvscreen.so

.include <bsd.port.mk>
