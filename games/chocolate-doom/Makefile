PORTNAME=	chocolate-doom
DISTVERSION=	3.1.1
CATEGORIES=	games

MAINTAINER=	jakub_lach@mailplus.pl
COMMENT=	Doom/Heretic/Hexen/Strife engine port compatible with the originals
WWW=		https://www.chocolate-doom.org/

LICENSE=	GPLv2

USES=		autoreconf gmake pkgconfig python:build sdl
USE_GITHUB=	yes
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}
USE_RC_SUBR=	chocolate-server
USE_SDL=	mixer2 net2 sdl2

GNU_CONFIGURE=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

PORTDOCS=	CMDLINE.doom ChangeLog INSTALL.doom NEWS.md NOT-BUGS.md \
		PHILOSOPHY.md README.md README.Music.md

OPTIONS_DEFINE=		DOCS FLUIDSYNTH PNG SAMPLERATE
OPTIONS_DEFAULT=	FLUIDSYNTH PNG SAMPLERATE
OPTIONS_SUB=		yes

DOCS_CONFIGURE_ENABLE=		doc

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_WITH=	fluidsynth

PNG_LIB_DEPENDS=		libpng.so:graphics/png
PNG_CONFIGURE_WITH=		libpng

SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_WITH=	libsamplerate

.include "${.CURDIR}/../doom-data/Makefile.include"

post-install:
	  ${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/chocolate-*

.include <bsd.port.mk>
