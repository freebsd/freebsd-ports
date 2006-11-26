# New ports collection makefile for:	gaia
# Date created:				23 November 2006
# Whom:					Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaia
PORTVERSION=	0.1.0
CATEGORIES=	astro
MASTER_SITES=	http://gaia.serezhkin.com/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Display geographic maps with optional GPS tracking support

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		SDL.11:${PORTSDIR}/devel/sdl12

USE_BZIP2=	yes
USE_SCONS=	yes

OPTIONS=	GPS "Build with GPS support" OFF

IGNORE=		distribution stopped due to complaints by Google (software changes required)

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GPS)
LIB_DEPENDS+=	gps.15:${PORTSDIR}/astro/gpsd
.else
SCONS_ARGS+=	gpsd=0
.endif

PLIST_FILES=	bin/gaia share/gaia/README share/gaia/font.png
PLIST_DIRS=	share/gaia

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; s|%%CXX%%|${CXX}|g ; \
		s|%%DATADIR%%|${PREFIX}/share/gaia| ; \
		s|%%CFLAGS%%|${CFLAGS}| ; \
		s|%%CXXFLAGS%%|${CXXFLAGS}|g' ${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gaia ${TARGETDIR}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/data/font.png ${DATADIR}/

.include <bsd.port.post.mk>
