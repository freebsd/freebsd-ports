# New ports collection makefile for:	gd
# Date created:				27 Mar 1998
# Whom:					jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	2.0.15
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

MAKE_ENV=	WRKSRC="${WRKSRC}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_XPM)
.if defined(WITHOUT_X11)
LIB_DEPENDS+=	Xpm:${PORTSDIR}/graphics/xpm
CPPFLAGS+=	-I${X11BASE}/include/X11 -I${X11BASE}/include -DHAVE_LIBXPM -DXPM_NOX
LDFLAGS+=	-L${X11BASE}/lib -lXpm
.else
USE_XPM=	yes
CPPFLAGS+=	-I${X11BASE}/include/X11 -I${X11BASE}/include -DHAVE_LIBXPM
LDFLAGS+=	-L${X11BASE}/lib -lXpm -lX11
.endif
.endif

.if defined(WITH_LZW) || defined(HAVE_UNISYS_LICENSE) || \
    (defined(USA_RESIDENT) && ${USA_RESIDENT} == "YES")
CPPFLAGS+=	-DLZW_LICENSED
.endif

.if defined(GD_FONTS)
USE_PERL5_BUILD=	yes
SCRIPTS_ENV+=	GD_FONTS="${GD_FONTS}"
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "gd has the following tunables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_XPM=yes			Turns on Xpm support"
	@${ECHO_MSG} "	WITH_XPM=yes WITHOUT_X11=yes	Turns on X-less Xpm support"
.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != "YES"
	@${ECHO_MSG} "	WITH_LZW=yes			Turns on GIF compression support"
.endif
	@${ECHO_MSG} ""

post-extract:
	@${CP} ${FILESDIR}/g* ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
