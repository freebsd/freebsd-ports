# Created by: Bruce Cran <bruce@cran.org.uk>
# $FreeBSD$

PORTNAME=	dfu-util
PORTVERSION=	0.8
CATEGORIES=	comms
MASTER_SITES=	http://dfu-util.gnumonks.org/releases/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Device firmware update (DFU) USB programmer

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	USE_LIBS="-lusb" \
		ac_cv_lib_usbpath_usb_path2devnum=no
CONFIGURE_ARGS=	--disable-silent-rules

PLIST_FILES=	bin/dfu-prefix bin/dfu-suffix bin/dfu-util man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
