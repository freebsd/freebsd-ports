# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstoedit
PORTVERSION=	3.70
PORTREVISION=	10
CATEGORIES=	graphics print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PostScript to other vector graphic formats

LICENSE=	GPLv2+

LIB_DEPENDS=	libgd.so:graphics/gd	\
		libzip.so:archivers/libzip

USES=		ghostscript libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG="${STRIP}"
USE_LDCONFIG=	yes

CPPFLAGS+=	-isystem ${LOCALBASE}/include/ming

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EMF EXAMPLES MAGICK MING PLOTUTILS
OPTIONS_DEFAULT=	EMF MAGICK MING PLOTUTILS
OPTIONS_SUB=		yes

EMF_DESC=		WMF/EMF support via libEMF
EMF_LIB_DEPENDS=	libEMF.so:graphics/libemf
EMF_CONFIGURE_ON=	--with-libemf-include=${LOCALBASE}/include/libEMF
EMF_CONFIGURE_OFF=	--without-emf
MAGICK_LIB_DEPENDS=	libMagick++-*.so:graphics/ImageMagick6
MAGICK_CONFIGURE_ON=	--with-magick
MAGICK_CONFIGURE_OFF=	--without-magick
MING_DESC=		Flash support via Ming
MING_LIB_DEPENDS=	libming.so:graphics/ming
MING_CONFIGURE_ON=	--with-swf
MING_CONFIGURE_OFF=	--without-swf
PLOTUTILS_DESC=		Plotting support via Plotutils
PLOTUTILS_LIB_DEPENDS=	libplotter.so:graphics/plotutils
PLOTUTILS_CONFIGURE_ON=	--with-libplot
PLOTUTILS_CONFIGURE_OFF=	--without-libplot

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="-g"|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|GraphicsMagick|Magick|g ; \
		 s|=$$OLDCPPFLAGS|=$$CPPFLAGS|g ; \
		 s|-lstdc++||g ; \
		 s|-pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ps ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
