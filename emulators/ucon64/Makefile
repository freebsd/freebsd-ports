PORTNAME=	ucon64
PORTVERSION=	2.2.1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTNAME:tl}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multipurpose video game ROM image and backup utility

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../license.html # only available as HTML file

USES=		gmake
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_ARGS=	CC="${CC}"

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/ucon64

OPTIONS_DEFINE=	CD64 COLOR DEBUG DISCMAGE PARALLEL USB ZLIB
OPTIONS_DEFAULT=CD64 COLOR DISCMAGE PARALLEL USB ZLIB
OPTIONS_SUB=	yes

CD64_DESC=	CD64 backup unit support
COLOR_DESC=	ANSI-colored output
DEBUG_DESC=	Additional debugging output
DISCMAGE_DESC=	ISO/BIN/CDI format support
PARALLEL_DESC=	Parallel port backup unit support
USB_DESC=	USB backup unit support
ZLIB_DESC=	ZIP/gzip archive support

CD64_CONFIGURE_WITH=		libcd64
COLOR_CONFIGURE_ENABLE=		ansi-color
DEBUG_CONFIGURE_ENABLE=		debug
DISCMAGE_CONFIGURE_WITH=	libdiscmage
DISCMAGE_PLIST_FILES=		lib/libdiscmage.so
PARALLEL_CONFIGURE_ENABLE=	parallel
USB_CONFIGURE_WITH=		libusb
ZLIB_CONFIGURE_WITH=		zlib

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ucon64.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ucon64_misc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DISCMAGE-on:
	${INSTALL_LIB} ${WRKSRC}/libdiscmage/discmage.so \
		${STAGEDIR}${PREFIX}/lib/libdiscmage.so

.include <bsd.port.mk>
