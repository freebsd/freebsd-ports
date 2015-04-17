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

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} -e 's/linux/${OPSYS:tl}/;s|gcc|${CC}|;s|g++|${CXX}|' \
	${WRKSRC}/pylib/gyp/generator/make.py

.include <bsd.port.post.mk>
