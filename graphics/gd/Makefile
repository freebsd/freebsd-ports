# New ports collection makefile for:	gd
# Date created:				27 Mar 1998
# Whom:					jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	2.0.35
PORTREVISION?=	0
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://www.libgd.org/releases/
MASTER_SITE_SUBDIR=	graphics/gd
PKGNAMESUFFIX?=	${NOX11_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
SCRIPTDIR=	${FILESDIR}
MAKE_ENV=	WRKSRC="${WRKSRC}" CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
CPPFLAGS+=	-DHAVE_ERRNO_H -DHAVE_FT2BUILD_H -DHAVE_LIBFREETYPE -DHAVE_LIBJPEG -DHAVE_LIBPNG \
		-DHAVE_LIBZ -DHAVE_STDDEF_H -DHAVE_STDINT_H -DHAVE_STDLIB_H
LDFLAGS2=	-L${PREFIX}/lib -L${LOCALBASE}/lib
FEATURES=	GD_JPEG GD_FREETYPE GD_PNG GD_GIF GD_GIFANIM GD_OPENPOLYGON
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)

.if defined(WITH_XPM)
USE_XPM=	yes
CPPFLAGS+=	-I${X11BASE}/include/X11 -I${X11BASE}/include -DHAVE_LIBXPM
LDFLAGS+=	-L${X11BASE}/lib -lXpm -lX11
LDFLAGS2+=	-L${X11BASE}/lib
FEATURES+=	GD_XPM
.endif

.if defined(WITH_FONTCONFIG)
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
CPPFLAGS+=	-I${X11BASE}/include -DHAVE_LIBFONTCONFIG -DHAVE_PTHREAD ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${X11BASE}/lib -lfontconfig
LDFLAGS2+=	${PTHREAD_LIBS} -L${X11BASE}/lib
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

FONTBASE=	${X11BASE}/lib/X11/fonts

pre-extract::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "gd has the following tunables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_XPM=yes			Turns on Xpm support"
	@${ECHO_MSG} "	WITH_FONTCONFIG=yes		Turns on Fontconfig support"
	@${ECHO_MSG} "	WITH_ICONV=yes			Turns on iconv support"
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
