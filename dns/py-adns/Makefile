# New ports collection makefile for:	py-adns
# Date created:		24 February 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	adns
PORTVERSION=	1.1.0
CATEGORIES=	dns python
MASTER_SITES=	http://dustman.net/andy/python/adns-python/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	adns-python-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	A Python Interface to adns, the asynchronous DNS library

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

post-patch:
	@${REINPLACE_CMD} -e 's|^\(include_dirs = \).*$$|\1\["${LOCALBASE}/include"\]|g' \
		-e 's|^\(library_dirs = \).*$$|\1\["${LOCALBASE}/lib"\]|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
