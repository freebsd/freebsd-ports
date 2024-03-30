PORTNAME=	pstoedit
DISTVERSION=	4.01
CATEGORIES=	graphics print
MASTER_SITES=	SF

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Convert PostScript to other vector graphic formats
WWW=		http://www.pstoedit.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/copying

LIB_DEPENDS=	libgd.so:graphics/gd \
		libzip.so:archivers/libzip

USES=		ghostscript gmake libtool localbase pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-docs=no
MAKE_ENV=	INSTALL_STRIP_FLAG="${STRIP}"
CPPFLAGS+=	-isystem ${LOCALBASE}/include/ming

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EMF EXAMPLES MAGICK MING PLOTUTILS
OPTIONS_DEFAULT=	EMF MAGICK MING PLOTUTILS
OPTIONS_SUB=		yes

EMF_DESC=	WMF/EMF support via libEMF
MING_DESC=	Flash support via Ming
PLOTUTILS_DESC=	Plotting support via Plotutils

EMF_LIB_DEPENDS=		libEMF.so:graphics/libemf
EMF_CONFIGURE_ON=		--with-libemf-include=${LOCALBASE}/include/libEMF
EMF_CONFIGURE_OFF=		--without-emf
MAGICK_USES=			magick
MAGICK_CONFIGURE_ON=		--with-magick
MAGICK_CONFIGURE_OFF=		--without-magick
MING_LIB_DEPENDS=		libming.so:graphics/ming
MING_CONFIGURE_ON=		--with-swf
MING_CONFIGURE_OFF=		--without-swf
PLOTUTILS_LIB_DEPENDS=		libplotter.so:graphics/plotutils
PLOTUTILS_CONFIGURE_ON=		--with-libplot
PLOTUTILS_CONFIGURE_OFF=	--without-libplot

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="-g"|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|GraphicsMagick|Magick|g ; \
		 s|=$$OLDCPPFLAGS|=$$CPPFLAGS|g ; \
		 s|-lstdc++||g ; \
		 s|-pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/src/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ps ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
