# ports collection makefile for:	xmysqladmin
# Date created:			Di   2 Sep 1997 16:29:27 CEST
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	xmysqladmin
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Contrib/Old-Versions

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 front end to the mysqladmin command of the MySQL database engine

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms \
		mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_XORG=	xpm
ALL_TARGET=	xmysqladmin

pre-su-install:
	@${MKDIR} ${PREFIX}/include/X11/pixmaps

.include <bsd.port.mk>
