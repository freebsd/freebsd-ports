# New ports collection makefile for:	gd
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	2.0.15
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

LATEST_LINK=	gd2

MAKE_ENV=	WRKSRC="${WRKSRC}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
INSTALLS_SHLIB=	yes

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
.if !defined(WITHOUT_XPM)
LIB_DEPENDS+=	Xpm:${PORTSDIR}/graphics/xpm
.endif
.else
USE_XPM=	yes
.endif

.if defined(WITH_LZW) || defined(HAVE_UNISYS_LICENSE) || \
    (defined(USA_RESIDENT) && ${USA_RESIDENT} == "YES")
CFLAGS+=	-DLZW_LICENSED
.endif

.if defined(GD_FONTS)
USE_PERL5_BUILD=	yes
SCRIPTS_ENV+=	GD_FONTS="${GD_FONTS}"
.endif

pre-everything::
.if !defined(WITH_LZW)
	@${ECHO_MSG} "************************************************************"
	@${ECHO_MSG} "*      If you live outside US and Canada, you can define   *"
	@${ECHO_MSG} "*      WITH_LZW to enable GIF compression support.         *"
	@${ECHO_MSG} "************************************************************"
.endif

post-extract:
	@${CP} ${FILESDIR}/g* ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
