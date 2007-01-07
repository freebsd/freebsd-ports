# New ports collection makefile for:	py-kid
# Date created:		2005-11-02
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	kid
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.kid-templating.org/dist/${PORTVERSION}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A simple template language for XML based written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree \
		easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_SUB+=	PYKID_EGG=${PYKID_EGG} \
		PYTHON_OLD=${PYTHON_OLD}

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	EGG="kid==${PYKID_VER}" \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTDOCS=	*

PYKID_EGG=	${PORTNAME}-${PYKID_VER}-py${PYTHON_VERSION:S/^python//}.egg
PYKID_VER=	${PORTVERSION}

SETUP_CFG=	setup.cfg

post-extract:
	${CP} ${FILESDIR}/${SETUP_CFG} ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${CP} README HISTORY COPYING misc/* ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}

	${MKDIR} ${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 250
PYTHON_OLD= "@comment "
.else
PYTHON_OLD= ""
.endif

.include <bsd.port.post.mk>
