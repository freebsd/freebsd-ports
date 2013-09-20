# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	libsigc++
PORTVERSION=	1.2.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool
LATEST_LINK=	libsigc++12
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
