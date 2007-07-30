# New ports collection makefile for:	py-json-py
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	json-py
PORTVERSION=	3.4
CATEGORIES=	devel lang www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A python implementation of a JSON (http//:json.org) reader/writer

NO_WRKSUBDIR=	yes

USE_PYTHON=	2.4+
USE_ZIP=	yes

do-build:
	# compile python files
	cd ${WRKDIR}; \
	FILES=$$(${FIND} . -name "*.py" ); \
	for FILE in $${FILES}; do \
	    ${ECHO} import `basename $${FILE} .py` | ${PYTHON_CMD}; \
	done; \

do-install:
	@cd ${WRKDIR}; \
	${FIND} . \( -name "*.py" -or -name "*.pyc" \) -exec ${INSTALL_SCRIPT} \{\} ${PYTHON_SITELIBDIR} \;

.include <bsd.port.mk>
