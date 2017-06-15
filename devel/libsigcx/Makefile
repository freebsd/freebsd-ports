# Created by: ijliao
# $FreeBSD$

PORTNAME=	libsigcx
PORTVERSION=	0.6.6
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension of libSigC++

BUILD_DEPENDS=	gm4:devel/m4
LIB_DEPENDS=	libsigc-1.2.so:devel/libsigc++12

OPTIONS_DEFINE=	STATIC

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_DOXYGEN=""
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

STATIC_CONFIGURE_ENABLE=	static
OPTIONS_SUB=	yes

.include <bsd.port.mk>
