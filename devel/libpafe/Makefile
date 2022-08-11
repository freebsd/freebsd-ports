PORTNAME=	libpafe
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	FeliCa read/write library for Sony RC-S320 USB FeliCa R/W(PaSoRi)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pkgconfig

PLIST_FILES=	bin/felica_dump bin/pasori_test \
		include/libpafe/felica_command.h \
		include/libpafe/libpafe.h \
		include/libpafe/pasori_command.h \
		lib/libpafe.a lib/libpafe.so lib/libpafe.so.0 \
		lib/libpafe.so.0.0.8

.include <bsd.port.mk>
