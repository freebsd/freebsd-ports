# Created by: Dominik Brettnacher <domi@nonsensss.de>
# $FreeBSD$

PORTNAME=	xsane
PORTVERSION=	0.999
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.xsane.org/download/

MAINTAINER=	koalative@gmail.com
COMMENT=	Gtk-based X11 frontend for SANE (Scanner Access Now Easy)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/xsane.COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		liblcms.so:graphics/lcms
BUILD_DEPENDS=	scanimage:graphics/sane-backends
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake jpeg localbase:ldflags pkgconfig
USE_GNOME=	gtk20 gdkpixbuf2
GNU_CONFIGURE=	yes

PORTDOCS=	*.html *.jpg

OPTIONS_DEFINE=	DOCS GIMP NLS
GIMP_DESC=	GIMP plugin support
OPTIONS_DEFAULT=	GIMP

OPTIONS_SUB=	yes

GIMP_LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app
GIMP_CONFIGURE_ENABLE=	gimp2 gimp
GIMP_SUB_FILES=		pkg-message
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_LIBS=		-L${LOCALBASE}/lib -lintl

post-patch:
	@${REINPLACE_CMD} -e 's| $$(DESTDIR)$$(sbindir)||' \
		-e 's|$${datadir}/sane/xsane/doc|${DOCSDIR}|g' \
		-e 's|$$(DESTDIR)$$(xsanedocdir)||' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|@POSUB@ doc|@POSUB@|' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.man ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
