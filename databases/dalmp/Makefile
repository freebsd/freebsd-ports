# Created by: Nicolas de Bari Embriz <nbari@dalmp.com>
# $FreeBSD$

PORTNAME=	dalmp
PORTVERSION= 	3.0.2
CATEGORIES=	databases

MAINTAINER=	nbari@dalmp.com
COMMENT=	Database Abstraction Layer for MySQL using PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		Unfetchable

USE_GITHUB=	yes
GH_ACCOUNT=	nbari
GH_PROJECT=	${PORTNAME:tu}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	72abf0c

USES=	tar:bzip2

NO_BUILD=	yes
USE_PHP=	pcre mysql mysqli session memcache sqlite3 curl

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
