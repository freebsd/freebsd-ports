# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	starfighter
PORTVERSION=	1.7
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/${PORTNAME}/${DISTVERSION} \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}-icons${EXTRACT_SUFX}:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	alfix86@gmail.com
COMMENT=	Liberate the universe from the evil company WEAPCO

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix gmake gnome iconv pkgconfig sdl
USE_SDL=	image2 mixer2

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-src

DOS2UNIX_GLOB=	*.txt

OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 32x32 48x48 64x64 72x72 96x96 128x128

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.mk>
