# Ports collection Makefile for:	py-functional
# Date created:				10/03/2000
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xoltar-toolkit
PORTVERSION=	2001.06.01
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-01jun01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Functional programming, lazy expressions and thread pools for Python

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
INSTALLDIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${MKDIR} ${INSTALLDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/*.py* ${INSTALLDIR}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
