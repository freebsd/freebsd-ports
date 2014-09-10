# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madedit
PORTVERSION=	0.2.9
PORTREVISION=	11
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/MadEdit/MadEdit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source and cross-platform text/hex editor

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs

USES=		gettext pkgconfig dos2unix desktop-file-utils
USE_WX=		2.8+
WANT_UNICODE=	yes
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
LIBS+=		-L${LOCALBASE}/lib -lX11

BROKEN_sparc64=	yes

.include <bsd.port.mk>
