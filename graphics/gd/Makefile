# Created by: jeff@cetlink.net
# $FreeBSD$

PORTNAME=	gd
PORTVERSION=	2.0.35
PORTREVISION?=	8
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://www.libgd.org/releases/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd
PKGNAMESUFFIX?=	${NOX11_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

CONFLICTS=	bazaar-1.*

USE_BZIP2=	yes
SCRIPTDIR=	${FILESDIR}
MAKE_ENV=	WRKSRC="${WRKSRC}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
CPPFLAGS+=	-DHAVE_ERRNO_H -DHAVE_FT2BUILD_H -DHAVE_LIBFREETYPE -DHAVE_LIBJPEG -DHAVE_LIBPNG \
		-DHAVE_LIBZ -DHAVE_STDDEF_H -DHAVE_STDINT_H -DHAVE_STDLIB_H
LDFLAGS+=	-L${WRKSRC}
LDFLAGS2=	-L${PREFIX}/lib -L${LOCALBASE}/lib
FEATURES=	GD_JPEG GD_FREETYPE GD_PNG GD_GIF GD_GIFANIM GD_OPENPOLYGON
USE_LDCONFIG=	yes
WANT_PERL=	yes

OPTIONS_DEFINE=	FONTCONFIG ICONV XPM
OPTIONS_DEFAULT=FONTCONFIG
NO_OPTIONS_SORT=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFONTCONFIG}
LIB_DEPENDS+=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_LIBFONTCONFIG -DHAVE_PTHREAD ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -lfontconfig
LDFLAGS2+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
FEATURES+=	GD_FONTCONFIG
.endif

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=	yes
CPPFLAGS+=	-DHAVE_ICONV -DHAVE_ICONV_H -DHAVE_ICONV_T_DEF
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
.endif

# honor global WITHOUT_X11
.if !defined(WITHOUT_X11)
.if ${PORT_OPTIONS:MXPM}
USE_XORG=	xpm x11
CPPFLAGS+=	-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include -DHAVE_LIBXPM
LDFLAGS+=	-L${LOCALBASE}/lib -lXpm -lX11
LDFLAGS2+=	-L${LOCALBASE}/lib
FEATURES+=	GD_XPM
.endif
.endif

FONTBASE=	${LOCALBASE}/lib/X11/fonts

# supprt for bitmap fonts
.if defined(GD_FONTS)
USE_PERL5_BUILD=	yes
SCRIPTS_ENV+=	GD_FONTS="${GD_FONTS}"
.endif

pre-extract::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "GD_FONTS can be set to specify an alternative list of .bdf files"
	@${ECHO_MSG} ""

post-configure:
	${SED} -e 's|@libdir@|${PREFIX}/lib|' \
		-e 's|@includedir@|${PREFIX}/include|' \
		-e 's|@VERSION@|${PORTVERSION}|' \
		-e 's|@GDLIB_MAJOR@|${PORTVERSION:C/([0-9]*).*/\1/1}|' \
		-e 's|@GDLIB_MINOR@|${PORTVERSION:C/[0-9]*[.]([0-9]).*/\1/1}|' \
		-e 's|@GDLIB_REVISION@|${PORTVERSION:C/.*[.]([0-9]*)/\1/1}|' \
		-e 's|@LDFLAGS@|${LDFLAGS2}|' \
		-e 's|@LIBS@|-lgd|' \
		-e 's|@LIBICONV@|${LIBICONV}|' \
		-e 's|@FEATURES@|${FEATURES}|' \
		${WRKSRC}/config/gdlib-config.in \
		> ${WRKDIR}/gdlib-config
	${REINPLACE_CMD} \
	-e 's|#define DEFAULT_FONTPATH .*|#define DEFAULT_FONTPATH "${FONTBASE}/TTF:${FONTBASE}/Type1:${FONTBASE}"|' \
		${WRKSRC}/gd.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/gdfx.h ${WRKSRC}/gdhelpers.h \
		${PREFIX}/include/
	${INSTALL_SCRIPT} ${WRKDIR}/gdlib-config ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
