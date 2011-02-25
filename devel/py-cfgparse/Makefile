# New ports collection makefile for:	cfgparse
# Date created:		March 18, 2008
# Whom:			John Ferrell
#
# $FreeBSD$
#

PORTNAME=	cfgparse
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v01_02
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cfgparse-v01_02

MAINTAINER=	jdferrell3@yahoo.com
COMMENT=	Python module for parsing configuration files

USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	cfgparse
PYDISTUTILS_EGGINFO=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-v01_02-${PYTHON_VERSION:S/thon//}.egg-info

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/cfgparse/* ${DOCSDIR}
.endif

PLIST_SUB=	PYTHONVER=${PYTHON_VERSION:S/python//}

.include <bsd.port.mk>
