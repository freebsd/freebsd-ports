# New ports collection makefile for:	graphics/linux-f8-cairo
# Date created:				2008-03-29
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	cairo
PORTVERSION=	1.4.14
PORTREVISION=	2
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Vector graphics library Cairo (Linux Fedora 8)

CONFLICTS=	linux-cairo-[0-9]* linux-f10-cairo-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	fontconfig png xorglibs
LINUX_DIST_VER=	8
RPMVERSION=	1.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libcairo.so.2 \
		usr/lib/libcairo.so.2.11.7
DOCSDIR=	${PREFIX}/usr/share/doc/cairo-${PORTVERSION}
PORTDOCS=	AUTHORS BIBLIOGRAPHY BUGS COPYING COPYING-LGPL-2.1 \
		COPYING-MPL-1.1 ChangeLog NEWS PORTING_GUIDE README ROADMAP TODO

.include <bsd.port.mk>
