# Ports collection makefile for:        py-geojson
# Date created:                 03 July, 2008
# Whom:                         Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	geojson
PORTVERSION=	1.0b1
CATEGORIES=	devel geography python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/g/geojson/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python's Encoder/decoder for simple GIS features

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>1.9:${PORTSDIR}/devel/py-simplejson

DOCSFILE=	CHANGES.txt CREDITS.txt DEPENDENCIES.txt FAQ.txt \
		GeoInterface.txt HISTORY.txt INSTALL.txt LICENSE.txt \
		README.txt VERSION.txt

USE_PYTHON=	2.4+
USE_PYDISTUTILS=easy_install
PYDISTUTILS_NOEGGINFO=	yes

post-install:
.if	!defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCSFILE}
	@cd ${WRKSRC} && ${CP} ${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
