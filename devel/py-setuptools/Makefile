# New ports collection makefile for:	py-setuptools
# Date created:		2005-11-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	setuptools
PORTVERSION=	0.6c5
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/s/setuptools/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Download, build, install, upgrade, and uninstall Python packages

DIST_SUBDIR=	python
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
