# New ports collection makefile for: 	gphoto
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gphoto2
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv \
		intl.1:${PORTSDIR}/devel/gettext \
		usb-0.1.5:${PORTSDIR}/devel/libusb \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-cdk --without-exif --without-fig2dev \
		--with-doc-dir=${DOCSDIR}
INSTALLS_SHLIB=	yes

MAN1=		gphoto2.1

INSTALL_CMD=	/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}

post-patch:
.for file in configure libgphoto2_port/configure
	@${PERL} -pi -e 's|<iconv.h>|<giconv.h>|g ; \
		 s|-liconv|-lgiconv|g ; \
		 s|-g -Wall||g' ${WRKSRC}/${file}
.endfor
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\@INSTALL\@|${INSTALL_CMD}|g ; \
		 s|AUTHORS COPYING README|AUTHORS README|g'

.include <bsd.port.mk>
