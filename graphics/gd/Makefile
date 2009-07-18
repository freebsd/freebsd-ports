# New ports collection makefile for:	gd
# Date created:				27 Mar 1998
# Whom:					jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	2.0.35
PORTREVISION?=	1
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://www.libgd.org/releases/
MASTER_SITE_SUBDIR=	graphics/gd
PKGNAMESUFFIX?=	${NOX11_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
SCRIPTDIR=	${FILESDIR}
MAKE_ENV=	WRKSRC="${WRKSRC}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
CPPFLAGS+=	-DHAVE_ERRNO_H -DHAVE_FT2BUILD_H -DHAVE_LIBFREETYPE -DHAVE_LIBJPEG -DHAVE_LIBPNG \
		-DHAVE_LIBZ -DHAVE_STDDEF_H -DHAVE_STDINT_H -DHAVE_STDLIB_H
LDFLAGS2=	-L${PREFIX}/lib -L${LOCALBASE}/lib
FEATURES=	GD_JPEG GD_FREETYPE GD_PNG GD_GIF GD_GIFANIM GD_OPENPOLYGON
USE_LDCONFIG=	yes
WANT_PERL=	yes

OPTIONS=	X11 "X11 support" off \
		XPM "XPM color bitmap loading support (requires X11)" off \
		FONTCONFIG "fontconfig library support (requires X11)" off \
		ICONV "iconv support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)

.if defined(WITH_XPM)
USE_XORG=	xpm x11
CPPFLAGS+=	-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include -DHAVE_LIBXPM
LDFLAGS+=	-L${LOCALBASE}/lib -lXpm -lX11
LDFLAGS2+=	-L${LOCALBASE}/lib
FEATURES+=	GD_XPM
.endif

.if defined(WITH_FONTCONFIG)
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_LIBFONTCONFIG -DHAVE_PTHREAD ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -lfontconfig
LDFLAGS2+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
FEATURES+=	GD_FONTCONFIG
.endif

.endif

.if defined(WITH_ICONV)
USE_ICONV=	yes
CPPFLAGS+=	-DHAVE_ICONV -DHAVE_ICONV_H -DHAVE_ICONV_T_DEF
LDFLAGS+=	-L${LOCALBASE}/lib -liconv
.endif

.if defined(GD_FONTS)
USE_PERL5_BUILD=	yes
SCRIPTS_ENV+=	GD_FONTS="${GD_FONTS}"
.endif

FONTBASE=	${LOCALBASE}/lib/X11/fonts

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

.include <bsd.port.post.mk>
