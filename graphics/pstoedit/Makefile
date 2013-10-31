# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstoedit
PORTVERSION=	3.62
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	SF

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Convert PostScript to other vector graphic formats

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

OPTIONS_DEFINE=	DOCS EMF EXAMPLES MAGICK MING PLOTUTILS
OPTIONS_DEFAULT=	EMF MAGICK MING PLOTUTILS

OPTIONS_SUB=	yes

EMF_DESC=	Enable emf interface
MING_DESC=	Enable swf interface
PLOTUTILS_DESC=	Enable libplot interface

USES=		pathfix pkgconfig
USE_GHOSTSCRIPT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*
PORTEXAMPLES=	*

EMF_LIB_DEPENDS=	libEMF.so:${PORTSDIR}/graphics/libemf
EMF_CONFIGURE_ON=	--with-libemf-include=${LOCALBASE}/include/libEMF
EMF__CONFIGURE_OFF=	--without-emf

MAGICK_LIB_DEPENDS=	libMagick++.so:${PORTSDIR}/graphics/ImageMagick
MAGICK_CONFIGURE_ON=	--with-magick
MAGICK_CONFIGURE_OFF=	--without-magick

MING_LIB_DEPENDS=	libming.so:${PORTSDIR}/graphics/ming
MING_CONFIGURE_ON=	--with-swf
MING_CONFIGURE_OFF=	--without-swf

PLOTUTILS_LIB_DEPENDS=	libplotter.so:${PORTSDIR}/graphics/plotutils
PLOTUTILS_CONFIGURE_ON=	--with-libplot
PLOTUTILS_CONFIGURE_OFF=	--without-libplot

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="-g"|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|GraphicsMagick|Magick|g ; \
		 s|=$$OLDCPPFLAGS|=$$CPPFLAGS|g ; \
		 s|-lstdc++||g ; \
		 s|-pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ps ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
