# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gyp
PORTVERSION=	r832
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	Generate Your Projects

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

pre-configure:
	${REINPLACE_CMD} -e 's/linux/${OPSYS:L}/;s|gcc|${CC}|;s|g++|${CXX}|' \
	${WRKSRC}/pylib/gyp/generator/make.py

.include <bsd.port.post.mk>
