# Created by: Oliver Lehmann
# $FreeBSD$

PORTNAME=	libwfut
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/libwfut%20%28updates%20library%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge update library

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		curl:${PORTSDIR}/ftp/curl

CONFIGURE_ARGS+=--without-python
GNU_CONFIGURE=	yes
USES=	pathfix pkgconfig
USE_LDCONFIG=	yes
MAN1=		wfut.1

post-patch:
	@${REINPLACE_CMD} -e 's/ python//g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
