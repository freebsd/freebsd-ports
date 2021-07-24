PORTNAME=	python2
PORTVERSION=	2
PORTREVISION=	3
CATEGORIES=	lang python
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	python@FreeBSD.org
COMMENT=	Meta-port for the Python interpreter 2.7

DEPRECATED=	EOLed upstream
EXPIRATION_DATE=	2020-12-31

USES=		python:2.7,run

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/2to3-2 \
		bin/idle2 \
		bin/pydoc2 \
		bin/python2 \
		bin/python2-config \
		libdata/pkgconfig/python2.pc

do-install:
.for file in idle pydoc python
	${LN} -sf ${file}${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/${file}2
.endfor
	${LN} -sf 2to3-${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/2to3-2
	${LN} -sf python${PYTHON_VER}-config \
		${STAGEDIR}${PREFIX}/bin/python2-config
	${LN} -sf python-${PYTHON_VER}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/python2.pc

.include <bsd.port.mk>
