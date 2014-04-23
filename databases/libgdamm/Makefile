# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgdamm/Makefile,v 1.21 2010/10/23 16:04:08 kwm Exp $

PORTNAME=	libgdamm
PORTVERSION=	3.99.21
PORTREVISION=	2
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2
PKGNAMESUFFIX=	-legacy

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgda4 library

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USES=		gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	glibmm libgda4
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdamm-4.0.so.12.0.0

.include <bsd.port.mk>
