# New ports collection makefile for:	odfpy
# Date created:		27 June 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	odfpy
PORTVERSION=	0.8
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}source/o/odfpy/ \
		http://opendocumentfellowship.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python API and Tools to Manipulate OpenDocument Files

PLIST_SUB+=	ODF_EGGINFO=${PYDISTUTILS_EGGINFO}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	odf
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_EGGINFO=	odfpy-0.8-py${PYTHON_VER}.egg-info

.include <bsd.port.mk>
