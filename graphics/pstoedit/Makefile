# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.44
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PostScript to other vector graphic formats

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

OPTIONS=	IMAGEMAGICK "Enable magick++ interface" on \
		EMF "Enable emf interface" on \
		MING "Enable swf interface" on \
		PLOTUTILS "Enable libplot interface" on

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GHOSTSCRIPT=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		pstoedit.1

CPPFLAGS=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include \
		-I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CFLAGS+=	-DHAVESTL -DHAVETYPENAME -DUSE_NEWSTRSTREAM -DHAVEAUTOPTR 
CPPFLAGS+=	-I${LOCALBASE}/include/stlport ${PTHREAD_CFLAGS}
LDFLAGS+=	-lstlport_gcc ${PTHREAD_LIBS}

.endif

.if defined(WITHOUT_IMAGEMAGICK)
CONFIGURE_ARGS+=	--without-magick
PLIST_SUB+=	IMAGEMAGICK="@comment "
.else
LIB_DEPENDS+=	Magick++.10:${PORTSDIR}/graphics/ImageMagick
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

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="-g"|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|GCC_OK=no|GCC_OK=yes|g ; \
		 s|GraphicsMagick|Magick|g ; \
		 s|=$$OLDCPPFLAGS|=$$CPPFLAGS|g ; \
		 s|-pedantic||g' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pstoedit.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
