# New ports collection makefile for: 	gphoto
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gphoto2
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.gphoto.net/dist/
MASTER_SITE_SUBDIR=	gphoto

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext \
		usb-0.1.5:${PORTSDIR}/devel/libusb \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		exif.5:${PORTSDIR}/graphics/libexif
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-cdk --without-fig2dev
INSTALLS_SHLIB=	yes

MAN1=		gphoto2.1

INSTALL_CMD=	/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}

post-patch:
.for file in configure libgphoto2_port/configure
	@${PERL} -pi -e 's|-g -Wall||g' ${WRKSRC}/${file}
.endfor
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\@INSTALL\@|${INSTALL_CMD}|g ; \
		 s| install-docDATA||g ; \
		 s| install-figureDATA||g ; \
		 s|`glib-config|`\$$\(GLIB_CONFIG\)|g ; \
		 s|\$$\(libdir\)/pkgconfig|\$$\(prefix\)/libdata/pkgconfig|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README doc/FAQ doc/gphoto2-cli.txt doc/gphoto2.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
