# New ports collection makefile for:	py-papi
# Date created:		2006-12-19
# Whom:			Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	papi
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	accessibility devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ocemp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@sysfault.org
COMMENT=	ATK accessibility wrapper for python

USE_GNOME=	atk
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PORTDOCS=	manual.html
PORTEXAMPLES=	atkaction.py atkapplication.py
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/papi.so

post-patch:
	${REINPLACE_CMD} -i "" -e 's|: docfiles|: []|g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/doc/examples && \
		${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
