# New ports collection makefile for:	gd
# Date created:				27 Mar 1998
# Whom:					jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	2.0.33
PORTREVISION?=	1
PORTEPOCH=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd
PKGNAMESUFFIX?=	${NOX11_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT?=	A graphics library for fast creation of images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

MAKE_ENV=	WRKSRC="${WRKSRC}" CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKEFILE=	${FILESDIR}/Makefile.bsd
INSTALLS_SHLIB=	yes
SCRIPTDIR=	${FILESDIR}
CPPFLAGS+=	-DHAVE_FT2BUILD_H

.include <bsd.port.pre.mk>

.if defined(WITH_XPM) && !defined(WITHOUT_X11)
USE_XPM=	yes
CPPFLAGS+=	-I${X11BASE}/include/X11 -I${X11BASE}/include -DHAVE_LIBXPM
LDFLAGS+=	-L${X11BASE}/lib -lXpm -lX11
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
	@${ECHO_MSG} ""

post-extract:
	@${CP} ${FILESDIR}/g* ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/gdfx.h ${WRKSRC}/gdhelpers.h \
		${PREFIX}/include/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
