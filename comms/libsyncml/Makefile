# New ports collection makefile for:	libsyncml
# Date created:		2008-03-09
# Whom:			Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	libsyncml
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://libsyncml.opensync.org/download/releases/${PORTVERSION}/ \
		http://mirror.roe.ch/dist/${PORTNAME}/

MAINTAINER=	daniel@roe.ch
COMMENT=	SyncML protocol library for PIM data synchronization

LIB_DEPENDS=	wbxml2:${PORTSDIR}/textproc/wbxml2 \
		openobex:${PORTSDIR}/comms/openobex \
		soup-2.2.8:${PORTSDIR}/devel/libsoup22

BROKEN=		does not compile

USE_AUTOTOOLS=	autoheader:262 automake:110 libtool:15
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-bluetooth --enable-obex --with-wbxml=${LOCALBASE}

MAN1=		syncml-http-server.1 syncml-obex-client.1

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
