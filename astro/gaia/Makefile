# New ports collection makefile for:	gaia
# Date created:				23 November 2006
# Whom:					Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaia
PORTVERSION=	0.1.2
PORTREVISION=	6
CATEGORIES=	astro
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	gaia-clean

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Display geographic maps with optional GPS tracking support

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_SCONS=	yes
SCONS_BUILDENV=	${SCONS_ENV}
SCONS_ARGS+=	prefix=${PREFIX} use_env=1
USE_SDL=	sdl

OPTIONS=	GPS "Build with GPS support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GPS)
LIB_DEPENDS+=	gps.18:${PORTSDIR}/astro/gpsd
SCONS_ARGS+=	gpsd=1
.endif

PLIST_FILES=	bin/gaia share/gaia/font.png
PLIST_DIRS=	share/gaia

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/SConstruct

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
