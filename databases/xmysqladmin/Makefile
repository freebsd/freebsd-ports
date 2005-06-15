# ports collection makefile for:	xmysqladmin
# Date created:			Di   2 Sep 1997 16:29:27 CEST
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	xmysqladmin
PORTVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	http://ftp.gwdg.de/pub/misc/mysql/Downloads/Contrib/ \
		http://ftp.rtfm.no/pub/mysql/Downloads/Contrib/ \
		ftp://mysql.secsup.org/pub/software/mysql/Downloads/Contrib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 front end to the mysqladmin command of the MySQL database engine

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms \
		mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_X_PREFIX=	yes
USE_XPM=	yes
ALL_TARGET=	xmysqladmin

pre-su-install:
	@${MKDIR} ${PREFIX}/include/X11/pixmaps

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-4
PLIST_SUB+=	NEWMTREE=""
.else
PLIST_SUB+=	NEWMTREE="@comment "
.endif

.include <bsd.port.post.mk>
