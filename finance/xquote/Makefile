# New ports collection makefile for:	xquote
# Date created:		4 Jan 1998
# Whom:			Ian Struble <ian@broken.net>
#
# $FreeBSD$

PORTNAME=	xquote
PORTVERSION=	2.6.9
CATEGORIES=	finance
MASTER_SITES=	http://xinvest.sunsite.dk/	\
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR= applications

MAINTAINER=	mph@freebsd.org
COMMENT=	A quote retrieval tool for X

LIB_DEPENDS=	Xbae.4:${PORTSDIR}/x11-toolkits/xbae

USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XPM=	yes

PLIST_FILES=	bin/Xquote lib/X11/app-defaults/Xquote

.include <bsd.port.mk>
