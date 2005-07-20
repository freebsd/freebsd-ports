# New ports collection makefile for:	nsping
# Date created:		04 March 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nsping
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	roam
DISTFILES=	nsping.tar.gz

MAINTAINER=	roam@FreeBSD.org
COMMENT=	DNS "ping"

MAN8=		nsping.8
PLIST_FILES=	sbin/nsping

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/nsping ${PREFIX}/sbin
		${INSTALL_DATA} ${WRKSRC}/nsping.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
