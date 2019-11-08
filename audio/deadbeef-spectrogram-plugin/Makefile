# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef-spectrogram-plugin
DISTVERSION=	0.0.2015.01.10
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Spectrogram plugin for DeaDBeeF audio player

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:audio/deadbeef
LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	cboxdoerfer
GH_PROJECT=	ddb_spectrogram
GH_TAGNAME=	8d1b371

USES=		gmake gnome pkgconfig

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

.for v in 2 3
GTK${v}_USE=	GNOME=gtk${v}0
GTK${v}_ALL_TARGET=	gtk${v}

GTK${v}_PLIST_FILES=	lib/deadbeef/ddb_vis_spectrogram_GTK${v}.so

do-install-GTK${v}-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/deadbeef
	${INSTALL_LIB} ${WRKSRC}/gtk${v}/ddb_vis_spectrogram_GTK${v}.so \
		${STAGEDIR}${PREFIX}/lib/deadbeef
.endfor

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
