# New ports collection makefile for:	gtkam
# Date created:			10 June 2002
# Whom:				ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtkam
PORTVERSION=	0.1.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gphoto

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Download and view files from various digital cameras

LIB_DEPENDS=	exif-gtk.4:${PORTSDIR}/graphics/libexif-gtk \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	libbonoboui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-gnome

MAN1=		gtkam.1

.if exists(${X11BASE}/lib/libgimp-1.3.so)
WITH_GIMP=	yes
.endif

.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp-1.3:${PORTSDIR}/graphics/gimp-devel
PLIST_SUB+=	GIMP=""
.else
CONFIGURE_ARGS=	--without-gimp
PLIST_SUB+=	GIMP="@comment "
.endif

pre-everything::
.if !defined(WITH_GIMP)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with plugin for The GIMP,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GIMP=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-g -Wall||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's| install-gtkamdocDATA||g ; \
		 s|images/gtkam|gtkam/images|g ; \
		 s|^test_fsel_LDFLAGS =.*|test_fsel_LDFLAGS = \$$(EXIF_LIBS)|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
