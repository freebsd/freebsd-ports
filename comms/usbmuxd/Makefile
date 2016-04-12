# $FreeBSD$

PORTNAME=	usbmuxd
DISTVERSION=	1.1.0
CATEGORIES=	comms
MASTER_SITES=	http://www.libimobiledevice.org/downloads/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Daemon for multiplexing connections over USB to iPhone/iPod Touch

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libplist.so:devel/libplist \
		libimobiledevice.so:comms/libimobiledevice

USES=		autoreconf cpe libtool pathfix pkgconfig tar:bzip2
CPE_VENDOR=	nikias_bassen
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-systemd \
		libusb_CFLAGS="-I/usr/include" \
		libusb_LIBS="-lusb"

PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
		sbin/${PORTNAME}

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
# TODO: add devd(8) rule.
	@${REINPLACE_CMD} \
		-e '/*cygwin*/ s,),|dragonfly*|*bsd*),' \
		${WRKSRC}/configure.ac

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
