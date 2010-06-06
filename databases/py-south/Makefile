# New ports collection makefile for:	py-south
# Date created:			July 29 2009
# Whom:				Stanislav Svirid <count@211.ru>
#
# $FreeBSD$
#

PORTNAME=	south
PORTVERSION=	0.7.1
CATEGORIES=	databases python
MASTER_SITES=	http://www.aeracode.org/releases/south/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	count@211.ru
COMMENT=	This is South, intelligent schema migrations for Django apps

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PYTHON=	yes
PYDISTUTILS_PKGNAME=	South
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
