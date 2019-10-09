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

# Major upgrade support
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portupgrade

.if defined(USE_PORTMASTER)
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portmaster
.endif

PKG_LIST=	${PKG_BIN} query -a '%n-%v'
PKG_LIST_FILES=	${PKG_INFO} -l

upgrade-site-packages:
	@if [ ! -x ${PORTUPGRADE_CMD} ]; then \
		${ECHO_MSG} "Please install ports-mgmt/portupgrade."; \
		${FALSE}; \
	 fi

	@GREP_ARGS="-q"; \
	for ver in `echo ${_PYTHON_ALLBRANCHES:C/${PYTHON_VER}//}`; do \
		GREP_ARGS="$${GREP_ARGS} -e lib/python$$ver"; \
	done; \
	UPD=""; \
	for pkg in `${PKG_LIST}`; do \
		${PKG_LIST_FILES} $${pkg} | ${GREP} $${GREP_ARGS} && \
			UPD="$${UPD} $${pkg}"; \
	done; \
	if [ "$${UPD}" ]; then \
		if [ -n ${PORTUPGRADE_ARGS} ]; then \
			${PORTUPGRADE_CMD} ${PORTUPGRADE_ARGS} -f $${UPD}; \
		else \
			${PORTUPGRADE_CMD} -f $${UPD}; \
		fi; \
	fi; \

.include <bsd.port.mk>
