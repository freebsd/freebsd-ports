# New ports collection makefile for:	gtkam
# Date created:			10 June 2002
# Whom:				ports@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtkam
PORTVERSION=	0.1.17
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/${PORTNAME}/${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Download and view files from various digital cameras

LIB_DEPENDS=	exif-gtk.5:${PORTSDIR}/graphics/libexif-gtk \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2

WANT_GNOME=	yes
USE_GNOME=	gnomehack gnomehier gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtkam.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgimp-2.0.so) && !defined(WITHOUT_GIMP)
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
	@${REINPLACE_CMD} -e 's|GIMP_VERSION="2.0"|GIMP_VERSION="2.2"|g ; \
		 s|images/gtkam|gtkam/images|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|images/gtkam|gtkam/images|g ; \
		 s|$$(libdir)/gimp/|$$(libexecdir)/gimp/|g'

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gtkam.desktop \
		${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gtkam.png \
		${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
