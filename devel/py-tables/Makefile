# ex:ts=8
# Ports collection makefile for:	PyTables
# Date created:			Dec 19, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tables
PORTVERSION=	0.7.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pytables
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytables-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hierarchical database for Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray
LIB_DEPENDS=	hdf5.0:${PORTSDIR}/graphics/hdf5 \
		lzo.1:${PORTSDIR}/archivers/lzo \
		ucl.0:${PORTSDIR}/archivers/ucl
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
