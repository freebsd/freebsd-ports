# New ports collection makefile for:	gtkam
# Date created:			10 June 2002
# Whom:				ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtkam
PORTVERSION=	0.1.12
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gphoto

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Download and view files from various digital cameras

LIB_DEPENDS=	exif-gtk.5:${PORTSDIR}/graphics/libexif-gtk \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnomehier gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtkam.1

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/lib/libgimp-2.0.so) && !defined(WITHOUT_GIMP)
WITH_GIMP=	yes
.endif

.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp-2.0:${PORTSDIR}/graphics/gimp
PLIST_SUB+=	GIMP=""
.else
CONFIGURE_ARGS+=	--without-gimp
PLIST_SUB+=	GIMP="@comment "
.endif

.if ${HAVE_GNOME:Mlibgnomeui}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomeprefix libgnomeui
INSTALLS_OMF=	yes
MAKE_ENV+=	GNOME_SUBDIRS="help omf-install"
DATADIR=	${PREFIX}/share/gnome/${PORTNAME}
.else
CONFIGURE_ARGS+=	--without-bonobo --without-gnome
MAKE_ENV+=	GNOME_SUBDIRS=""
.endif

pre-everything::
.if !defined(WITH_GIMP)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with plugin for The GIMP,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GIMP=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-g -Wall||g ; \
		 s|gimpui-1.3|gimpui-2.0|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|images/gtkam|gtkam/images|g ; \
		 s|-pedantic||g ; \
		 s|$$(libdir)/gimp/1.3/|$$(libexecdir)/gimp/2.2/|g'
	@${ECHO_CMD} "Icon=gtkam.png" >> ${WRKSRC}/gtkam.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/gtkam.desktop \
		${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/gtkam.png \
		${PREFIX}/share/gnome/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
