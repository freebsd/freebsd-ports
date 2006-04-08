# New ports collection makefile for:	py-setuptools
# Date created:		2005-11-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	setuptools
PORTVERSION=	0.6a11
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/s/setuptools/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Download, build, install, upgrade, and uninstall Python packages

USE_ZIP=	yes
DIST_SUBDIR=	python
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PLIST_SUB=	VERSION=${PORTVERSION} PYVER=${PYTHON_VERSION:S/python//}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
