# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	easyrpg-player
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	RPG Maker 2000/2003 and EasyRPG games interpreter

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		liblcf.so:games/liblcf \
		libharfbuzz.so:print/harfbuzz \
		libmpg123.so:audio/mpg123 \
		libvorbis.so:audio/libvorbis \
		libsndfile.so:audio/libsndfile \
		libxmp.so:audio/libxmp \
		libspeexdsp.so:audio/speexdsp \
		libopusfile.so:audio/opusfile
BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	EasyRPG
GH_PROJECT=	Player

USES=		autoreconf compiler:c++11-lib gmake libtool localbase pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bash-completion-dir=${PREFIX}/share/bash-completion/completions
USE_XORG=	pixman
USE_SDL=	sdl2 mixer2

PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
