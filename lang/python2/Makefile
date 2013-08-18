# $FreeBSD$

PORTNAME=	python2
PORTVERSION=	${PYTHON_MAJOR_VER}
CATEGORIES=	lang python ipv6
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	python@FreeBSD.org
COMMENT=	The "meta-port" for version 2 of the Python interpreter

USE_PYTHON_RUN=	yes
PYTHON_VERSION=	${PYTHON_DEFAULT_VERSION}
NO_BUILD=	yes
PYTHON_NO_DEPENDS=	yes

PLIST_FILES=	bin/2to3-${PYTHON_MAJOR_VER} \
		bin/idle${PYTHON_MAJOR_VER} \
		bin/pydoc${PYTHON_MAJOR_VER} \
		bin/python${PYTHON_MAJOR_VER} \
		bin/python${PYTHON_MAJOR_VER}-config \
		bin/python-shared${PYTHON_MAJOR_VER} \
		bin/python-shared${PYTHON_MAJOR_VER}-config \
		bin/smtpd${PYTHON_MAJOR_VER}.py

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}

do-install:
.for file in idle pydoc python python-shared
	${LN} -sf ${PREFIX}/bin/${file}${PYTHON_VER} ${PREFIX}/bin/${file}${PYTHON_MAJOR_VER}
.endfor
	${LN} -sf ${PREFIX}/bin/2to3-${PYTHON_VER} ${PREFIX}/bin/2to3-${PYTHON_MAJOR_VER}
	${LN} -sf ${PREFIX}/bin/smtpd${PYTHON_VER}.py ${PREFIX}/bin/smtpd${PYTHON_MAJOR_VER}.py
	${LN} -sf ${PREFIX}/bin/python${PYTHON_VER}-config ${PREFIX}/bin/python${PYTHON_MAJOR_VER}-config
	${LN} -sf ${PREFIX}/bin/python-shared${PYTHON_VER}-config ${PREFIX}/bin/python-shared${PYTHON_MAJOR_VER}-config

# Major upgrade support
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portupgrade

.if defined(USE_PORTMASTER)
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portmaster
.endif

.if defined(WITH_PKGNG)
PKG_LIST=	${PKG_BIN} query -a '%n-%v'
PKG_LIST_FILES=	${PKG_INFO} -l
.else
PKG_LIST=	${PKG_INFO} -Ea
PKG_LIST_FILES=	${PKG_INFO} -L
.endif

.include <bsd.port.post.mk>
