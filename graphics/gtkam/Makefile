# Created by: ports@FreeBSD.org
# $FreeBSD$

PORTNAME=	gtkam
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/gphoto/${PORTNAME}/${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Download and view files from various digital cameras

LICENSE=	GPLv2+

LIB_DEPENDS=	libexif-gtk.so:graphics/libexif-gtk \
		libgphoto2.so:graphics/libgphoto2

USES=		gettext gmake gnome pathfix pkgconfig
USE_GNOME=	gtk20 intltool
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS GIMP GNOME
OPTIONS_SUB=	yes

GIMP_DESC=		GIMP plugin support
GIMP_LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp
GIMP_CONFIGURE_WITH=	gimp

GNOME_USE=		GNOME=gnomeprefix,libgnomeui
GNOME_CONFIGURE_OFF=	--without-bonobo --without-gnome
GNOME_MAKE_ENV=		GNOME_SUBDIRS="help omf-install"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
INSTALLS_OMF=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|GIMP_VERSION="2.0"|GIMP_VERSION="2.2"|g ; \
		 s|images/gtkam|gtkam/images|g ; \
		 s|FLAGS -g|FLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's/$$(GNOME_LIBS)/& $$(GTK_LIBS)/' \
		${WRKSRC}/src/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|images/gtkam|gtkam/images|g ; \
		 s|$$(libdir)/gimp/|$$(libexecdir)/gimp/|g'

.include <bsd.port.mk>
