# New ports collection makefile for:	sane-backends
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane-backends
PORTVERSION=	1.0.13
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/%SUBDIR%/ \
		ftp://ftp.de.mostang.com/pub/sane/%SUBDIR%/ \
		ftp://ftp.no.mostang.com/pub/sane/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION} \
			old-versions/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for access to scanners, digitals camera, frame grabbers etc

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		usb-0.1.7:${PORTSDIR}/devel/libusb \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ENV=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_GPHOTO2)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/gphoto2
CONFIGURE_ARGS+=	--with-gphoto2=yes
PLIST_SUB+=	GPHOTO2=""
.else
PLIST_SUB+=	GPHOTO2="@comment "
.endif

pre-everything::
.if !defined(WITH_GPHOTO2)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with gPhoto2 support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GPHOTO2=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -I/usr/local/include||g ; \
		 s|gphoto2 2.0.1|gphoto2 2.0|g' ${WRKSRC}/configure

.include "Makefile.man"
.include <bsd.port.post.mk>
