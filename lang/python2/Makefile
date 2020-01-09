# $FreeBSD$

PORTNAME=	python2
PORTVERSION=	${PYTHON_MAJOR_VER}
PORTREVISION=	3
CATEGORIES=	lang python
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	python@FreeBSD.org
COMMENT=	The "meta-port" for version 2 of the Python interpreter

DEPRECATED=	EOLed upstream
EXPIRATION_DATE=	2020-12-31

USES=		python:2.7,run

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/2to3-${PYTHON_MAJOR_VER} \
		bin/idle${PYTHON_MAJOR_VER} \
		bin/pydoc${PYTHON_MAJOR_VER} \
		bin/python${PYTHON_MAJOR_VER} \
		bin/python${PYTHON_MAJOR_VER}-config \
		libdata/pkgconfig/python${PYTHON_MAJOR_VER}.pc

do-install:
.for file in idle pydoc python
	${LN} -sf ${file}${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/${file}${PYTHON_MAJOR_VER}
.endfor
	${LN} -sf 2to3-${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/2to3-${PYTHON_MAJOR_VER}
	${LN} -sf python${PYTHON_VER}-config \
		${STAGEDIR}${PREFIX}/bin/python${PYTHON_MAJOR_VER}-config
	${LN} -sf python-${PYTHON_VER}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/python${PYTHON_MAJOR_VER}.pc

.include <bsd.port.mk>
