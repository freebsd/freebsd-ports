# New ports collection makefile for:	py-papi
# Date created:		2006-12-19
# Whom:			Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	papi
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	accessibility devel python
MASTER_SITES=	SF/ocemp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@sysfault.org
COMMENT=	ATK accessibility wrapper for python

USE_GNOME=	atk
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

EXAMPLES=	atkaction.py atkapplication.py atkcapi.c msaaapplication.py \
		msaacapi.cpp

post-patch:
	${REINPLACE_CMD} -i "" -e 's|: docfiles|: []|g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/doc/examples && \
		${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
