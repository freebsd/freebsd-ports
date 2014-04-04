# Created by: Nicolas de Bari Embriz <nbari@dalmp.com>
# $FreeBSD$

PORTNAME=	dalmp
PORTVERSION=	2.1
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	nbari@dalmp.com
COMMENT=	Database Abstraction Layer for MySQL using PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		tar:bzip2

DEFAULT_VERSIONS=php=5

NO_BUILD=	yes
USE_PHP=	pcre mysql mysqli session memcache sqlite3 curl

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
