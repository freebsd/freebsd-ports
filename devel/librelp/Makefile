# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librelp
PORTVERSION=	1.2.7
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/librelp/

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Reliable event logging protocol library

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

USES=		libtool pathfix pkgconfig
USE_AUTOTOOLS=	automake aclocal
USE_LDCONFIG=	yes

PLIST_FILES=	include/${PORTNAME}.h \
		lib/${PORTNAME}.a \
		lib/${PORTNAME}.so lib/${PORTNAME}.so.0 \
		lib/${PORTNAME}.so.0.1.0 \
		libdata/pkgconfig/relp.pc

PORT_VERBS=	relp

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS/s| -g||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librelp.so.0.1.0

.include <bsd.port.mk>
