# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	json-py
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	devel lang www python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/3_4
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python implementation of a JSON (http//:json.org) reader/writer

LICENSE=	LGPL20

NO_WRKSUBDIR=	yes

USES=		zip
USE_PYTHON=	yes

do-build:
	# compile python files
	cd ${WRKDIR}; \
	FILES=$$(${FIND} . -name "*.py" ); \
	for FILE in $${FILES}; do \
	    ${ECHO} import `basename $${FILE} .py` | ${PYTHON_CMD}; \
	done; \

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	@cd ${WRKDIR}; \
	${FIND} . \( -name "*.py" -or -name "*.pyc" \) -exec ${INSTALL_SCRIPT} \{\} ${STAGEDIR}${PYTHON_SITELIBDIR} \;

.include <bsd.port.mk>
