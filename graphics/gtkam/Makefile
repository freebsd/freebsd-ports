# New ports collection makefile for:	gtkam
# Date created:			10 June 2002
# Whom:				ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtkam
PORTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gphoto

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	exif-gtk.4:${PORTSDIR}/graphics/libexif-gtk \
		gphoto2.2:${PORTSDIR}/graphics/gphoto2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp1
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
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${DOCSDIR}
.endif

.include <bsd.port.mk>
