# Created by: ijliao
# $FreeBSD$

PORTNAME=	libsigcx
PORTVERSION=	0.6.6
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extension of libSigC++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

USES=		pathfix gmake pkgconfig
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	ac_cv_path_DOXYGEN=""
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
