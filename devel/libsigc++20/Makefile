# New ports collection makefile for:   libsigc++
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	libsigc++
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.2 \
		libsigc
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GMAKE=	yes
LATEST_LINK=	libsigc++12
INSTALLS_SHLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
USE_LIBTOOL=	yes

.include <bsd.port.mk>
