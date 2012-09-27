# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	${PYTHON_VER}
PORTEPOCH=	2
CATEGORIES=	lang python ipv6
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	python@FreeBSD.org
COMMENT=	The "meta-port" for the default version of Python interpreter

USE_PYTHON_RUN=	yes
PYTHON_VERSION=	${PYTHON_DEFAULT_VERSION}
NO_BUILD=	yes

do-install:
	@${DO_NADA}

# Major upgrade support
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portupgrade

.if defined(USE_PORTMASTER)
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portmaster
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
	for pkg in `${PKG_INFO} -Ea`; do \
		${PKG_INFO} -L $${pkg} | ${GREP} $${GREP_ARGS} && \
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
