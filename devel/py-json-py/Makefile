# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	json-py
DISTVERSION=	3_4
PORTREVISION=	1
CATEGORIES=	devel lang www python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python implementation of a JSON (http//:json.org) reader/writer

LICENSE=	LGPL20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

NO_WRKSUBDIR=	yes

USES=		python:2.7 zip

do-build:
	# compile python files
	cd ${WRKSRC}; \
	FILES=$$(${FIND} . -name "*.py" ); \
	for FILE in $${FILES}; do \
	    ${ECHO} import `basename $${FILE} .py` | ${PYTHON_CMD}; \
	done; \

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	@cd ${WRKSRC}; \
	${FIND} . \( -name "*.py" -or -name "*.pyc" \) -exec ${INSTALL_SCRIPT} \{\} ${STAGEDIR}${PYTHON_SITELIBDIR} \;

.include <bsd.port.mk>
