# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.41
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PostScript to other vector graphic formats

OPTIONS=	IMAGEMAGICK "Enable magick++ interface" on \
		EMF "Enable emf interface" on \
		MING "Enable swf interface" on \
		PLOTUTILS "Enable libplot interface" on

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GHOSTSCRIPT=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=	pstoedit.1

CPPFLAGS=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include \
		-I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CFLAGS+=	-DHAVESTL -DHAVETYPENAME -DUSE_NEWSTRSTREAM
.endif

.if defined(WITHOUT_IMAGEMAGICK)
CONFIGURE_ARGS+=	--without-magick
PLIST_SUB+=	IMAGEMAGICK="@comment "
.else
LIB_DEPENDS+=	Magick++.8:${PORTSDIR}/graphics/ImageMagick
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
LIB_DEPENDS+=	ming.3:${PORTSDIR}/graphics/ming
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
		 s|-pedantic||g' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pstoedit.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
