# New ports collection makefile for:	gd
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd

MAINTAINER?=	ports@FreeBSD.org

PORTCOMMENT=	A graphics library for fast creation of images

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		freetype:${PORTSDIR}/print/freetype2

LATEST_LINK=	gd2

.ifndef WITHOUT_XPM
# Temporary hack, until X-less XPM building is added to USE_XPM:
.ifndef WITHOUT_X11
USE_XPM=	yes
.else
LIB_DEPENDS+=	Xpm:${PORTSDIR}/graphics/xpm
.endif
.else
MAKE_ARGS+=	-DWITHOUT_XPM
.endif

INSTALLS_SHLIB=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j2
.for v in WRKSRC INSTALL_PROGRAM INSTALL_DATA INSTALL_SCRIPT
MAKE_ARGS+=	$v="${$v}"
.endfor

pre-fetch:
.if !defined(WITH_LZW)
	@${ECHO_CMD} "************************************************************"
	@${ECHO_CMD} "*      If you live outside US and Canada, you can define   *"
	@${ECHO_CMD} "*      WITH_LZW to enable GIF compression support.         *"
	@${ECHO_CMD} "************************************************************"
.endif

post-extract:
	@${CP} ${FILESDIR}/g* ${WRKSRC}

post-patch:
.if !defined(WITH_LZW)
	${MV} ${WRKSRC}/gd_gif_out.c ${WRKSRC}/gd_gif_out.c.nogif && \
		${SED} -e "s|#define LZW_LICENCED||g" \
			< ${WRKSRC}/gd_gif_out.c.nogif \
			> ${WRKSRC}/gd_gif_out.c
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.if defined(GD_FONTS)
BUILD_DEPENDS=	perl:${PORTSDIR}/lang/perl5
SCRIPTS_ENV+=	GD_FONTS="${GD_FONTS}"
.endif

.include <bsd.port.mk>
