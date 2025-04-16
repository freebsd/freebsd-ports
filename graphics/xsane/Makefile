PORTNAME=	xsane
DISTVERSION=	0.999
PORTREVISION=	11
CATEGORIES=	graphics

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Gtk-based X11 frontend for SANE (Scanner Access Now Easy)
WWW=		https://gitlab.com/sane-project/frontend/xsane

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/xsane.COPYING

BR_DEPENDS=	scanimage:graphics/sane-backends
BUILD_DEPENDS=	${BR_DEPENDS}
LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		liblcms.so:graphics/lcms
RUN_DEPENDS=	${BR_DEPENDS}

USES=		gmake gnome jpeg localbase:ldflags pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.com/sane-project
GL_ACCOUNT=	frontend
USE_GNOME=	gdkpixbufextra:run gtk20
GNU_CONFIGURE=	yes

PORTDOCS=	*.html *.jpg

OPTIONS_DEFINE=	DOCS GIMP NLS
OPTIONS_DEFAULT=	GIMP
OPTIONS_SUB=	yes

GIMP_DESC=	GIMP plugin support

GIMP_LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
			libgegl-0.4.so:graphics/gegl \
			libgegl-npd-0.4.so:graphics/gegl \
			libgimp-2.0.so:graphics/gimp-app \
			libbabl-0.1.so:x11/babl
GIMP_CONFIGURE_ENABLE=	gimp2 gimp
GIMP_SUB_FILES=		pkg-message
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=		-L${LOCALBASE}/lib -lintl

post-patch:
	@${REINPLACE_CMD} -e 's| $$(DESTDIR)$$(sbindir)||' \
		-e 's|$${datadir}/sane/xsane/doc|${DOCSDIR}|g' \
		-e 's|$$(DESTDIR)$$(xsanedocdir)||' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|@POSUB@ doc|@POSUB@|' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.man ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
