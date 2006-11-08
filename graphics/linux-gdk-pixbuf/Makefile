# New ports collection makefile for:	linux-gdk-pixbuf
# Date created:		23 December 2003
# Whom:			Seth Kingsley <sethk@meowfishies.com>
#
# $FreeBSD$
#

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.22.0.18.fc4.2
CATEGORIES=	graphics linux
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^([^\.]+\.[^\.]+\.[^\.]+)\./\1-/}

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Linux version of the graphic library for GTK+

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
ONLY_FOR_ARCHS=	i386 amd64
INSTALLS_SHLIB=	yes
PLIST_SUB=	VERSION=${PORTVERSION:C/^([^\.]+\.[^\.]+\.[^\.]+).+/\1/}
MD5_FILE?=	${PKGDIR}/distinfo

.include <bsd.port.mk>
