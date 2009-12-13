# New ports collection makefile for:	py-setuptools
# Date created:		2005-11-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	setuptools
PORTVERSION=	0.6c11
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Download, build, install, upgrade, and uninstall Python packages

DIST_SUBDIR=	python
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

.include <bsd.port.pre.mk>

.if ${PYTHON_SUFFIX} < 25
PLIST_SUB+=	PYTHON_CURRENT="@comment "
PLIST_SUB+=	PYTHON_OLD=""
.else
PLIST_SUB+=	PYTHON_CURRENT=""
PLIST_SUB+=	PYTHON_OLD="@comment "
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/site.py ${PYTHON_SITELIBDIR}
.for opt in -Qold -O
	${PYTHON_CMD} ${opt} -m compileall -l -x \
		'^[^s][^i]?[^t]?[^e]?[^.][^p][^y]$$' ${PYTHON_SITELIBDIR}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
