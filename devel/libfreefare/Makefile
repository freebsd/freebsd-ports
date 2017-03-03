# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	libfreefare
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://${PORTNAME}.googlecode.com/files/ \
		http://romain.blogreen.org/distfiles/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	MIFARE contactless tag access library

BROKEN=		Unfetchable (google code has gone away)
DEPRECATED=	Unfetchable for more than six months (google code has gone away)
EXPIRATION_DATE=	2017-04-30

LIB_DEPENDS=	libnfc.so:devel/libnfc

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pathfix gmake pkgconfig tar:bzip2 libtool ssl
MAKE_ENV=	INSTALL_STRIP_FLAG="${STRIP}"
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
