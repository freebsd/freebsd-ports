# New ports collection makefile for:	mysql_last_value
# Date created:			14th Aug 2003
# Whom:	                        Aftab Jahan Subedar
# $FreeBSD$

PORTNAME=       mysql_last_value
PORTVERSION=    3.2
CATEGORIES=	databases
MASTER_SITES=   http://www.geocities.com/jahan.geo/

MAINTAINER=	jahan@bol-online.com
COMMENT=	Replaces NULL value of current column with value from top row

LIB_DEPENDS=	mysqlclient.14:${PORTSDIR}/databases/mysql41-client

PLIST_FILES=	bin/mysql_last_value
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mysql_last_value ${PREFIX}/bin

.include <bsd.port.mk>
