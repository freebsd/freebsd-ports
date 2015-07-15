# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gyp
PORTVERSION=	20150414
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Generate Your Projects

LICENSE=	BSD3CLAUSE

USES=		python:2
USE_PYTHON=	autoplist distutils

pre-configure:
	${REINPLACE_CMD} -e 's/linux/${OPSYS:tl}/;s|gcc|${CC}|;s|g++|${CXX}|' \
	${WRKSRC}/pylib/gyp/generator/make.py

.include <bsd.port.mk>
