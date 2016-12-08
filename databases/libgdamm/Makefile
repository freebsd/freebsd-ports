# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgdamm/Makefile,v 1.21 2010/10/23 16:04:08 kwm Exp $

PORTNAME=	libgdamm
PORTVERSION=	3.99.21
PORTREVISION=	4
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2
PKGNAMESUFFIX=	-legacy

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgda4 library

BUILD_DEPENDS=	gm4:devel/m4

USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	glibmm libgda4
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
