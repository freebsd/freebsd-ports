# Created by: ijliao
# $FreeBSD$

PORTNAME=	libsigcx
PORTVERSION=	0.6.6
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension of libSigC++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	libsigc-1.2.so:${PORTSDIR}/devel/libsigc++12

OPTIONS_DEFINE=	STATIC

USES=		gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_DOXYGEN=""
USE_LDCONFIG=	yes

STATIC_CONFIGURE_ENABLE=	static
OPTIONS_SUB=	yes

.include <bsd.port.mk>
