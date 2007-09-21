# New ports collection makefile for:	libdnsres
# Date created:				Fri Feb  3 18:15:51 MST 2006
# Whom:					Phil Oleson <oz@nixil.net>
#
# $FreeBSD$
#

PORTNAME=	libdnsres
PORTVERSION=	0.1a
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	oz@nixil.net
COMMENT=	Provides a non-blocking thread-safe API for resolving DNS names

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN3=	dnsres.3
MLINKS=	dnsres.3 dnsres_init.3 dnsres.3 dnsres_gethostbyname.3 \
	dnsres.3 dnsres_gethostbyname2.3 dnsres.3 dnsres_gethostbyaddr.3 \
	dnsres.3 dnsres_getaddrinfo.3

post-patch:
	@${REINPLACE_CMD} -e 's,CFLAGS =,CFLAGS +=,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
