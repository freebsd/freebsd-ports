# $FreeBSD$

PORTNAME=	python3
PORTVERSION=	${PYTHON_MAJOR_VER}
PORTREVISION=	3
CATEGORIES=	lang python
MASTER_SITES=
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	python@FreeBSD.org
COMMENT=	The "meta-port" for version 3 of the Python interpreter

USES=		python:run

NO_ARCH=	yes
NO_BUILD=	yes
PYTHON_VERSION=	python${PYTHON3_DEFAULT}

PLIST_FILES=	bin/2to3-${PYTHON_MAJOR_VER} \
		bin/idle${PYTHON_MAJOR_VER} \
		bin/pydoc${PYTHON_MAJOR_VER} \
		bin/python${PYTHON_MAJOR_VER} \
		bin/python${PYTHON_MAJOR_VER}-config \
		libdata/pkgconfig/python${PYTHON_MAJOR_VER}.pc

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}

do-install:
	${LN} -sf python${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/python${PYTHON_MAJOR_VER}
	${LN} -sf 2to3-${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/2to3-${PYTHON_MAJOR_VER}
.for file in idle pydoc
	${LN} -sf ${file}${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/${file}${PYTHON_MAJOR_VER}
.endfor
	${LN} -sf python${PYTHON_VER}-config \
		${STAGEDIR}${PREFIX}/bin/python${PYTHON_MAJOR_VER}-config
	${LN} -sf python-${PYTHON_VER}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/python${PYTHON_MAJOR_VER}.pc

# Major upgrade support
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portupgrade

.if defined(USE_PORTMASTER)
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portmaster
.endif

PKG_LIST=	${PKG_BIN} query -a '%n-%v'
PKG_LIST_FILES=	${PKG_INFO} -l

.include <bsd.port.post.mk>
