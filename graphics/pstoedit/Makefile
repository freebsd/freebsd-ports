# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.45
PORTREVISION=	3
CATEGORIES=	graphics print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PostScript to other vector graphic formats

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

OPTIONS=	IMAGEMAGICK "Enable magick++ interface" on \
		EMF "Enable emf interface" on \
		MING "Enable swf interface" on \
		PLOTUTILS "Enable libplot interface" on

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GHOSTSCRIPT=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=		pstoedit.1

CPPFLAGS=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include \
		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IMAGEMAGICK)
CONFIGURE_ARGS+=	--without-magick
PLIST_SUB+=	IMAGEMAGICK="@comment "
.else
LIB_DEPENDS+=	Magick++.2:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	IMAGEMAGICK=""
.endif

.if defined(WITHOUT_EMF)
CONFIGURE_ARGS+=	--without-emf
PLIST_SUB+=	EMF="@comment "
.else
LIB_DEPENDS+=	EMF.1:${PORTSDIR}/graphics/libemf
CONFIGURE_ARGS+=	--with-libemf-include=${LOCALBASE}/include/libEMF
PLIST_SUB+=	EMF=""
.endif

.if defined(WITHOUT_MING)
CONFIGURE_ARGS+=	--without-swf
PLIST_SUB+=	MING="@comment "
.else
LIB_DEPENDS+=	ming.4:${PORTSDIR}/graphics/ming
PLIST_SUB+=	MING=""
.endif

.if defined(WITHOUT_PLOTUTILS)
CONFIGURE_ARGS+=	--without-libplot
PLIST_SUB+=	PLOTUTILS="@comment "
.else
LIB_DEPENDS+=	plotter.4:${PORTSDIR}/graphics/plotutils
PLIST_SUB+=	PLOTUTILS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="-g"|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|GraphicsMagick|Magick|g ; \
		 s|=$$OLDCPPFLAGS|=$$CPPFLAGS|g ; \
		 s|-pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pstoedit.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
