# New ports collection makefile for:	gd
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	1.8.4
PORTREVISION=	5
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/ \
		http://virtual-estates.net/~mi/port-stuff/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} gd_gif_in.c.bz2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	ports@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2     # XXX
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2
.if !exists(/usr/bin/bzip2)
BUILD_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

FREETYPE_CONFIG?=       ${LOCALBASE}/bin/freetype-config

MAKE_ENV=	FREETYPE_CONFIG="${FREETYPE_CONFIG}"
INSTALLS_SHLIB=	yes

.if defined(WITH_X11)
USE_XPM=	yes
.endif

pre-everything::
.if !defined(WITH_X11)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Xpm support,"
	@${ECHO_MSG} "hst Ctrl-C right now and use \"make WITH_X11=yes\""
	@${ECHO_MSG}
.endif

post-extract:
	@bzip2 -dc ${DISTDIR}/${DIST_SUBDIR}/gd_gif_in.c.bz2 \
		> ${WRKSRC}/gd_gif_in.c

post-patch:
	@${PERL} -pi -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/gdcache.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
