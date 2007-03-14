# New ports collection makefile for:	openobex
# Date created:				15 March 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	openobex
PORTVERSION=	1.3
CATEGORIES=	comms net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mad@madpilot.net
COMMENT=	Open source implementation of the OBEX protocol

USE_AUTOTOOLS=	automake:14:env autoheader:259 autoconf:259 libtool:15
USE_GMAKE=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-transform-name="" \
			--disable-usb

post-patch:
	@ ${REINPLACE_CMD} -e "s|pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
