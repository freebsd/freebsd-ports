# New ports collection makefile for:	mysql-udf-sys
# Date created:		December 2011
# Whom:			David Cornejo <dave@dogwood.com>
#
# $FreeBSD$
#

PORTNAME=	mysql-udf-sys
PORTVERSION=	0.0.3
CATEGORIES=	databases
MASTER_SITES=	http://www.mysqludf.org/lib_mysqludf_sys/
DISTNAME=	lib_mysqludf_sys_${PORTVERSION}

MAINTAINER=	dave@dogwood.com
COMMENT=	System access UDFs

USE_MYSQL=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	lib/mysql/plugin/lib_mysqludf_sys.so
PLIST_DIRS=	lib/mysql/plugin

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|; s|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
