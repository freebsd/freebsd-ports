# New ports collection makefile for:	mysql-navigator
# Date created:				2 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-navigator
PORTVERSION=	0.3.2
CATEGORIES=	databases gnome
MASTER_SITES=	http://sql.kldp.org/source/
DISTNAME=	mysql_navigator_ver_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_X_PREFIX=	yes
USE_GNOME=	yes

ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mn ${PREFIX}/bin/

.include <bsd.port.mk>
