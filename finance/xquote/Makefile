# New ports collection makefile for:	xquote
# Date created:		4 Jan 1998
# Whom:			Ian Struble <ian@broken.net>
#
# $FreeBSD$

PORTNAME=	xquote
PORTVERSION=	2.6.10
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	SF/xinvest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A quote retrieval tool for X

DEPRECATED=	Outdated, abandoned
EXPIRATION_DATE=	2011-05-01

LIB_DEPENDS=	Xbae.4:${PORTSDIR}/x11-toolkits/xbae

USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XORG=	xpm

PLIST_FILES=	bin/Xquote lib/X11/app-defaults/Xquote

.include <bsd.port.mk>
