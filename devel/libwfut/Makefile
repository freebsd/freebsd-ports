# New ports collection makefile for:	libwfut
# Date created:				4th April 2007
# Whom:					Oliver Lehmann
#
# $FreeBSD$
#

PORTNAME=	libwfut
PORTVERSION=	0.2.2
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/libwfut%20%28updates%20library%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge update library

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		curl.6:${PORTSDIR}/ftp/curl

CONFIGURE_ARGS+=--without-python
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
MAN1=		wfut.1

post-patch:
	@${REINPLACE_CMD} -e 's/ python//g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
