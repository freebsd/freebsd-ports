PORTNAME=	libconfig
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://research.wand.net.nz/software/libconfig/ \
		http://matt.peterson.org/FreeBSD/ports/
PKGNAMEPREFIX=	wand-

MAINTAINER=	matt@peterson.org
COMMENT=	C library for parsing config files

CONFLICTS=	libconfig

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	include/libconfig.h lib/libconfig.a \
		lib/libconfig.so lib/libconfig.so.1 \
		lib/libconfig.so.1.0.4

.include <bsd.port.mk>
