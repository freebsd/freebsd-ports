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
PKG_WHICH_CMD=	${LOCALBASE}/sbin/pkg_which
XARGS_CMD=	${XARGS} -0

.if defined(USE_PORTMASTER)
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portmaster
PORTUPGRADE_ARGS?=	""
PKG_WHICH_CMD=	/usr/sbin/pkg_info -qW
JOBS=	${SYSCTL} -n kern.smp.cpus
XARGS_CMD=	${XARGS} -L 1 -0 -P $$(${JOBS})
.endif

upgrade-site-packages:
	@if [ ! -x ${PORTUPGRADE_CMD} ]; then \
		${ECHO_MSG} "Please install ports-mgmt/portupgrade."; \
		${FALSE}; \
	 fi

	@for ver in `echo ${_PYTHON_ALLBRANCHES}|${SED} 's/${PYTHON_VER}//'`; do \
		if [ -d ${PREFIX}/lib/python$$ver ]; then \
			UPD=`${FIND} ${PREFIX}/lib/python$$ver \
					-type f -print0 | \
				${XARGS_CMD} ${PKG_WHICH_CMD} | \
				${GREP} -Fv '?' | \
				${EGREP} -v '^python2?[0-5]?-2' | \
				${SORT} -u`; \
			if [ "$$UPD" ]; then \
				if [ -n ${PORTUPGRADE_ARGS} ]; then \
					${PORTUPGRADE_CMD} ${PORTUPGRADE_ARGS} -f $$UPD; \
				else \
					${PORTUPGRADE_CMD} -f $$UPD; \
				fi; \
			fi; \
		fi; \
	 done \

.include <bsd.port.mk>
