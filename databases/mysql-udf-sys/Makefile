# Created by: David Cornejo <dave@dogwood.com>
# $FreeBSD$

PORTNAME=	mysql-udf-sys
PORTVERSION=	0.0.3
CATEGORIES=	databases
MASTER_SITES=	http://www.mysqludf.org/lib_mysqludf_sys/
DISTNAME=	lib_mysqludf_sys_${PORTVERSION}

MAINTAINER=	dave@dogwood.com
COMMENT=	System access UDFs

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USE_MYSQL=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	lib/mysql/plugin/lib_mysqludf_sys.so

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|; s|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
