# New ports collection makefile for:    python
# Date created:         08 August 1995
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.4.4
PORTEPOCH=	1
CATEGORIES=	lang python ipv6
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	python@FreeBSD.org
COMMENT=	The "meta-port" for the stable version of Python interpreter

USE_PYTHON_RUN=	yes
PYTHON_VERSION=	python2.4
NO_BUILD=	yes

do-install: # empty

# Major upgrade support
PORTUPGRADE?=	${LOCALBASE}/sbin/portupgrade
PKG_WHICH?=	${LOCALBASE}/sbin/pkg_which
upgrade-site-packages:
	@if [ -x ${PORTUPGRADE} ]; then \
		for ver in 2.1 2.2 2.3 2.5; do \
			if [ -d ${PREFIX}/lib/python$$ver ]; then \
				UPD=`${FIND} ${PREFIX}/lib/python$$ver \
						-type f -print0 | \
					${XARGS} -0 ${PKG_WHICH} | \
					${GREP} -Fv '?' | \
					${EGREP} -v '^python2?[0-5]?-2' | \
					${SORT} -u`; \
				if [ "$$UPD" ]; then \
					${PORTUPGRADE} -f $$UPD; \
				fi; \
			fi; \
		done; \
	 else \
		${ECHO_MSG} "Please install ports-mgmt/portupgrade."; \
		${FALSE}; \
	 fi

.include <bsd.port.mk>
