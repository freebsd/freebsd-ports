# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef-musical-spectrum-plugin
DISTVERSION=	0.0.2015.10.13
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Musical spectrum plugin for DeaDBeeF audio player

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:audio/deadbeef
LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	cboxdoerfer
GH_PROJECT=	ddb_musical_spectrum
GH_TAGNAME=	353870a

USES=		gmake gnome pkgconfig

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

MAKE_JOBS_UNSAFE=	yes

.for v in 2 3
GTK${v}_USE=	GNOME=gtk${v}0

GTK${v}_PLIST_FILES=	lib/deadbeef/ddb_vis_musical_spectrum_GTK${v}.so
GTK${v}_ALL_TARGET=	gtk${v}

do-install-GTK${v}-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/deadbeef
	${INSTALL_LIB} ${WRKSRC}/gtk${v}/ddb_vis_musical_spectrum_GTK${v}.so \
		${STAGEDIR}${PREFIX}/lib/deadbeef
.endfor

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
