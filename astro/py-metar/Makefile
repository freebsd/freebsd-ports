# New ports collection makefile for:	py-metar
# Date created:		26 July 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	metar
PORTVERSION=	0.8
CATEGORIES=	astro python
MASTER_SITES=	http://unattached.i-no.de/pkgs/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pymetar-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python module that provides access to NOAA's METAR weather reports

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

post-extract:
	${CP} ${WRKSRC}/bin/pymet2.py ${WRKSRC}/bin/pymet2

post-patch:
	${REINPLACE_CMD} 's,bin/pymet2.py,bin/pymet2,g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
