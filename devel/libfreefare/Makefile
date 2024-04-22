PORTNAME=	libfreefare
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	romain@FreeBSD.org
COMMENT=	MIFARE contactless tag access library
WWW=		https://github.com/nfc-tools/libfreefare/

LICENSE=	LGPL3+

LIB_DEPENDS=	libnfc.so:devel/libnfc

USE_GITHUB=	yes
GH_ACCOUNT=	nfc-tools
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_LDCONFIG=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig ssl
MAKE_ENV=	INSTALL_STRIP_FLAG="${STRIP}"
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
