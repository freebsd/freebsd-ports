# New ports collection makefile for:	py-babel
# Date created:		7 July 2007
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	Babel
PORTVERSION=	0.8.1
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/babel/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A collection of tools for internationalizing Python applications

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
BABELVER?=	${PORTVERSION}
PYTHONVER?=	${_PYTHON_VERSION}
PLIST_SUB=	BABELVER=${BABELVER} \
		PYTHONVER=${PYTHONVER}

.if !defined(NOPORTDOCS)
PORTDOCS=	doc/*
.endif

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION}"

PYBABEL_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VERSION:S/^python//}.egg

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${CP} -r ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
