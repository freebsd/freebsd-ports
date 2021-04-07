PORTNAME=	avrdude
PORTVERSION=	6.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH/avrdude
PKGNAMEPREFIX=	arduino-

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Program for programming the on-chip memory of Atmel AVR Arduino CPUs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libftdi1.so:devel/libftdi1

GNU_CONFIGURE=	yes
USES=		libtool localbase readline
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	PKGNAMEPREFIX=${PKGNAMEPREFIX}

CONFIGURE_ARGS+=	--disable-shared --disable-static

PLIST_FILES=	bin/arduino-avrdude \
		etc/arduino-avrdude.conf \
		man/man1/arduino-avrdude.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-lusb-1.0|-lusb|g' ${WRKSRC}/configure

post-configure:
	@${MV} ${WRKSRC}/${PORTNAME}.1 ${WRKSRC}/${PKGNAMEPREFIX}${PORTNAME}.1
	@${MV} ${WRKSRC}/${PORTNAME}.conf ${WRKSRC}/${PKGNAMEPREFIX}${PORTNAME}.conf

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/lib${PORTNAME}.h
	@${RM} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.a

.include <bsd.port.mk>
