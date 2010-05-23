# New ports collection makefile for:	py-adns
# Date created:		24 February 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	adns
PORTVERSION=	1.2.1
CATEGORIES=	dns python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	adns-python-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python Interface to adns, the asynchronous DNS library

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns

PROJECTHOST=	adns-python
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	adns-python
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

post-patch:
	@${REINPLACE_CMD} -e 's|^\(include_dirs = \).*$$|\1\["${LOCALBASE}/include"\]|g' \
		-e 's|^\(library_dirs = \).*$$|\1\["${LOCALBASE}/lib"\]|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
