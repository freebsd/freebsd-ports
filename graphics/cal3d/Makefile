# New ports collection makefile for:	cal3d
# Date created:				12 Jul 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	cal3d
PORTVERSION=	0.9.1
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	Skeletal based 3d character animation library written in C++

USE_BZIP2=		yes
USE_GNOME=		pkgconfig
USE_AUTOMAKE_VER=	19
USE_AUTOHEADER_VER=	259
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=		yes

.include <bsd.port.pre.mk>

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOHEADER}

.include <bsd.port.post.mk>
