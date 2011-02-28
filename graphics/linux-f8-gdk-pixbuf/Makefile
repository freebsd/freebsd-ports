# New ports collection makefile for:	devel/linux-f8-gdk-pixbuf
# Date created:				2008-04-02
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Image loading library for GTK+ (Linux Fedora 8)

CONFLICTS=	linux-gdk-pixbuf-[0-9]* linux-f10-gdk-pixbuf-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	35.fc8
USE_LDCONFIG=	yes

.include <bsd.port.mk>
