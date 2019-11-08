# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef-waveform-seekbar-plugin
DISTVERSION=	0.0.2016.01.01
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Waveform seekbar plugin for DeaDBeeF audio player

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:audio/deadbeef
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	cboxdoerfer
GH_PROJECT=	ddb_waveform_seekbar
GH_TAGNAME=	0402f6d

USES=		gmake gnome pkgconfig sqlite

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

.for v in 2 3
GTK${v}_USE=	GNOME=gtk${v}0

GTK${v}_ALL_TARGET=	gtk${v}
GTK${v}_PLIST_FILES=	lib/deadbeef/ddb_misc_waveform_GTK${v}.so

do-install-GTK${v}-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/deadbeef
	${INSTALL_LIB} ${WRKSRC}/gtk${v}/ddb_misc_waveform_GTK${v}.so \
		${STAGEDIR}${PREFIX}/lib/deadbeef
.endfor

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
