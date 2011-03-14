# New ports collection makefile for:	dalmp
# Date created:		06 Nov 2010
# Whom:			Nicolas de Bari Embriz <nbari@dalmp.com>
#
# $FreeBSD$
#

PORTNAME=	dalmp
PORTVERSION=	0.9.297
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	nbari@dalmp.com
COMMENT=	Database Abstraction Layer for MySQL using PHP

USE_BZIP2=	YES
LICENSE=	BSD

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

NO_BUILD=	YES
USE_PHP=	pcre mysql mysqli session memcache sqlite curl

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/ ${DATADIR}

.include <bsd.port.mk>
