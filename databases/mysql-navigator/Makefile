# New ports collection makefile for:	mysql-navigator
# Date created:				2 June 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql-navigator
PORTVERSION=	0.3.2
CATEGORIES=	databases gnome
MASTER_SITES=	http://sql.kldp.org/source/
DISTNAME=	mysql_navigator_ver_${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		mysqlclient.6:${PORTSDIR}/databases/mysql322-client

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mn ${PREFIX}/bin/

.include <bsd.port.mk>
