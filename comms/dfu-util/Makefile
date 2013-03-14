# Created by: Bruce Cran <bruce@cran.org.uk>
# $FreeBSD$

PORTNAME=	dfu-util
PORTVERSION=	0.7
CATEGORIES=	comms
MASTER_SITES=	http://dfu-util.gnumonks.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Device firmware update (DFU) USB programmer

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	USE_LIBS="-lusb" \
		ac_cv_lib_usbpath_usb_path2devnum=no
CONFIGURE_ARGS=	--disable-silent-rules
MAKE_JOBS_SAFE=	yes

MAN1=		dfu-util.1
PLIST_FILES=	bin/dfu-suffix bin/dfu-util

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
IGNORE=		requires new USB stack in FreeBSD 8
.endif

.include <bsd.port.post.mk>
