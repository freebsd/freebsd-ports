# Created by: jkh
# $FreeBSD$

PORTNAME=	python
PORTVERSION=	${PYTHON_DEFAULT}
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	lang python ipv6
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	python@FreeBSD.org
COMMENT=	The "meta-port" for the default version of Python interpreter

USE_PYTHON_RUN=	yes
NO_BUILD=	yes
PYTHON_NO_DEPENDS=	yes

PLIST_FILES=	bin/2to3 \
		bin/idle \
		bin/pydoc \
		bin/python \
		bin/python-config \
		bin/python-shared \
		bin/python-shared-config

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} == 2
RUN_DEPENDS+=	python2:${PORTSDIR}/lang/python2
PLIST_FILES+=	bin/smtpd.py
.elif ${PYTHON_MAJOR_VER} == 3
RUN_DEPENDS+=	python3:${PORTSDIR}/lang/python3
.endif

do-install:
.for file in python python-shared
	${LN} -sf ${PREFIX}/bin/${file}${PYTHON_MAJOR_VER} ${PREFIX}/bin/${file}
.endfor
	${LN} -sf ${PREFIX}/bin/2to3-${PYTHON_MAJOR_VER} ${PREFIX}/bin/2to3
.if ${PYTHON_MAJOR_VER} == 2
	${LN} -sf ${PREFIX}/bin/smtpd${PYTHON_MAJOR_VER}.py ${PREFIX}/bin/smtpd.py
.for file in idle pydoc
	${LN} -sf ${PREFIX}/bin/${file}${PYTHON_MAJOR_VER} ${PREFIX}/bin/${file}
.endfor
.elif ${PYTHON_MAJOR_VER} == 3
.for file in idle pydoc
	${LN} -sf ${PREFIX}/bin/${file}${PYTHON_MAJOR_VER}-${PYTHON_VER} ${PREFIX}/bin/${file}
.endfor
.endif
	${LN} -sf ${PREFIX}/bin/python${PYTHON_MAJOR_VER}-config ${PREFIX}/bin/python-config
	${LN} -sf ${PREFIX}/bin/python-shared${PYTHON_MAJOR_VER}-config ${PREFIX}/bin/python-shared-config

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

.include <bsd.port.post.mk>
