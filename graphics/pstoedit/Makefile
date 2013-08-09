# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pstoedit
PORTVERSION=	3.62
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	SF

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Convert PostScript to other vector graphic formats

LICENSE=	GPLv2

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

OPTIONS_DEFINE=	MAGICK EMF MING PLOTUTILS
OPTIONS_DEFAULT=	MAGICK EMF PLOTUTILS
EMF_DESC=	Enable emf interface
MING_DESC=	Enable swf interface
PLOTUTILS_DESC=	Enable libplot interface

USES=		pathfix pkgconfig
USE_GHOSTSCRIPT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		pstoedit.1

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAGICK}
LIB_DEPENDS+=	Magick++:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	IMAGEMAGICK=""
.else
CONFIGURE_ARGS+=	--without-magick
PLIST_SUB+=	IMAGEMAGICK="@comment "
.endif

.if ${PORT_OPTIONS:MEMF}
LIB_DEPENDS+=	EMF:${PORTSDIR}/graphics/libemf
CONFIGURE_ARGS+=	--with-libemf-include=${LOCALBASE}/include/libEMF
PLIST_SUB+=	EMF=""
.else
CONFIGURE_ARGS+=	--without-emf
PLIST_SUB+=	EMF="@comment "
.endif

.if ${PORT_OPTIONS:MMING}
LIB_DEPENDS+=	ming:${PORTSDIR}/graphics/ming
PLIST_SUB+=	MING=""
.else
CONFIGURE_ARGS+=	--without-swf
PLIST_SUB+=	MING="@comment "
.endif

.if ${PORT_OPTIONS:MPLOTUTILS}
LIB_DEPENDS+=	plotter:${PORTSDIR}/graphics/plotutils
PLIST_SUB+=	PLOTUTILS=""
.else
CONFIGURE_ARGS+=	--without-libplot
PLIST_SUB+=	PLOTUTILS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="-g"|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|GraphicsMagick|Magick|g ; \
		 s|=$$OLDCPPFLAGS|=$$CPPFLAGS|g ; \
		 s|-pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ps ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
