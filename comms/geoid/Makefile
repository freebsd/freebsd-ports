# New ports collection makefile for:	geoid
# Date created:				March 20 2007
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	geoid
PORTVERSION=	1.0
PORTREVISION=	2
DISTVERSIONSUFFIX=	.src
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/LinuxApps/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	fl_geoid
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Geodetic computer for amateur radio use

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk-threads

USE_GMAKE=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/geoid ${DATADIR_REL}/country.pos share/pixmaps/geoid.png
PLIST_DIRS=	${DATADIR_REL}

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/geoid.cxx

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/geoid ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/geoid.png ${PREFIX}/share/pixmaps
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA}	${WRKSRC}/country.pos ${DATADIR}

.include <bsd.port.mk>
