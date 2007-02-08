# New ports collection makefile for:	py-kid
# Date created:		2005-11-02
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	kid
PORTVERSION=	0.9.5
#PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	http://www.kid-templating.org/dist/${PORTVERSION}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A simple template language for XML based written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree \
		${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_SUB+=	PYKID_EGG=${PYKID_EGG} \
		EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		EGG="kid==${PYKID_VER}"

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-N -O1 -s ${PREFIX}/bin -S ${PYTHON_SITELIBDIR} dist/${PYKID_EGG}

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTDOCS=	*

EASY_INSTALL_CMD=	easy_install-${PYTHON_VER}
PYKID_EGG=	${PORTNAME}-${PYKID_VER}-py${PYTHON_VER}.egg
PYKID_VER=	${PORTVERSION}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${CP} README HISTORY COPYING misc/* ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}

	${MKDIR} ${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
