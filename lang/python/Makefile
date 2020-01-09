# Created by: jkh
# $FreeBSD$

PORTNAME=	python
PORTVERSION=	${PYTHON_DEFAULT}
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	lang python
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	python@FreeBSD.org
COMMENT=	"meta-port" for the default version of Python interpreter

RUN_DEPENDS=	python${PYTHON_MAJOR_VER}:lang/python${PYTHON_MAJOR_VER}

USES=		python:run

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/2to3 \
		bin/idle \
		bin/pydoc \
		bin/python \
		bin/python-config

do-install:
	${LN} -sf 2to3-${PYTHON_MAJOR_VER} ${STAGEDIR}${PREFIX}/bin/2to3
.for file in idle pydoc python
	${LN} -sf ${file}${PYTHON_MAJOR_VER} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
	${LN} -sf python${PYTHON_MAJOR_VER}-config ${STAGEDIR}${PREFIX}/bin/python-config

.include <bsd.port.mk>
