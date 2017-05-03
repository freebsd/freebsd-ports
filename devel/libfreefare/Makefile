# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	libfreefare
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	romain@FreeBSD.org
COMMENT=	MIFARE contactless tag access library

LICENSE=	LGPL3+

LIB_DEPENDS=	libnfc.so:devel/libnfc

USE_GITHUB=	yes
GH_ACCOUNT=	nfc-tools
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig ssl
MAKE_ENV=	INSTALL_STRIP_FLAG="${STRIP}"
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
