# New ports collection makefile for:	py-metar
# Date created:		26 July 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	metar
PORTVERSION=	0.14
CATEGORIES=	astro python geography
MASTER_SITES=	http://www.schwarzvogel.de/pkgs/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymetar-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python module that provides access to NOAA's METAR weather reports

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pymetar

PLIST_FILES=	bin/weather.py \
		%%PYTHON_SITELIBDIR%%/pymetar.py \
		%%PYTHON_SITELIBDIR%%/pymetar.pyc \
		%%PYTHON_SITELIBDIR%%/pymetar.pyo

PORTDOCS=	COPYING README THANKS librarydoc.txt

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|"share/doc/pymetar-%s/"%pymetar.__version__|"${DOCSDIR}"|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
