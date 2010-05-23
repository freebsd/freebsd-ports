# New ports collection makefile for:	py-iconv
# Date created:		11 September 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$

PORTNAME=	iconv
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An iconv wrapper with unicode codec for Python

USE_ICONV=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}

SETUPINFO=	,libraries=["iconv"],library_dirs=["${LOCALBASE}/lib"],\
		include_dirs=["${LOCALBASE}/include"]

post-patch:
	cd ${WRKSRC} && ${SED} 's!^\(.*ext_mod.*\)\()]\)$$!\1${SETUPINFO}\2!g'\
		setup.py > setup.py.tmp && ${CAT} setup.py.tmp > setup.py

.include <bsd.port.mk>
