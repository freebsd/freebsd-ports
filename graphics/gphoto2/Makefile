# New ports collection makefile for: 	gphoto
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gphoto2
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.gphoto.net/dist/
MASTER_SITE_SUBDIR=	gphoto

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext \
		usb-0.1.5:${PORTSDIR}/devel/libusb \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		exif.8:${PORTSDIR}/graphics/libexif
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--without-cdk --without-fig2dev --without-xmlto
INSTALLS_SHLIB=	yes

MAN1=		gphoto2.1
MAN3=		gphoto2.3 gphoto2_port.3

post-patch:
.for file in configure libgphoto2_port/configure
	@${REINPLACE_CMD} -e 's|-g -Wall||g ; \
		 s|-pthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/${file}
.endfor
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|`glib-config|`\$$(GLIB_CONFIG)|g ; \
		 s| install-docDATA||g ; \
		 s| install-figureDATA||g ; \
		 s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README doc/FAQ doc/gphoto2-cli.txt doc/gphoto2.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${PREFIX}/share/doc/libgphoto2_port
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/libgphoto2_port/${file} \
		${PREFIX}/share/doc/libgphoto2_port
.endfor
.endif

.include <bsd.port.mk>
