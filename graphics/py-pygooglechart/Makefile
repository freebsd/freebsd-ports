# Created by: Nicola Vitale	<nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygooglechart
PORTVERSION=	0.3.0
PORTREVISION=	0
CATEGORIES=	graphics python
MASTER_SITES=	http://pygooglechart.slowchop.com/files/download/ \
		LOCAL/nivit/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Complete Python wrapper for the Google Chart API

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

PORTEXAMPLES=	*

.if !defined(NOPORTEXAMPLES)
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
NO_STAGE=	yes
post-install:
	${MKDIR} ${EXAMPLESDIR} && cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
