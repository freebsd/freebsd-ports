# $FreeBSD$

PORTNAME=	geoid
PORTVERSION=	1.0
DISTVERSIONSUFFIX=	.src
PORTREVISION=	9
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/LinuxApps/
DISTNAME=	fl_geoid
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Geodetic computer for amateur radio use

BROKEN=		unfetchable

LICENSE=	GPLv2+ NONE  # only one src file contains license
LICENSE_COMB=	multi

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

USES=		gmake jpeg xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender
MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/geoid.cxx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geoid ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/geoid.png ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/country.pos ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
