# New ports collection makefile for:   libsigc++
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	libsigc++
PORTVERSION=	1.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.2 \
		libsigc
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_GMAKE=	yes
LATEST_LINK=	libsigc++12
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LIBTOOL_VER=	15

.include <bsd.port.mk>
