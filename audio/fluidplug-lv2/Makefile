# $FreeBSD$

PORTNAME=	FluidPlug
PORTVERSION=	g20161020
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SoundFonts as LV2 plugins via FluidSynth

LICENSE=	LGPL20

BUILD_DEPENDS=	7z:archivers/p7zip \
		lv2>0:audio/lv2
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	falkTX
GH_TAGNAME=	889b256

SOUNDFONT_DIR=	${PREFIX}/share/sounds/sf2

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|PREFIX  = /usr|PREFIX ?= /usr| ; \
		s|wget .*\/\(.*\) \&\& \\|${LN} -s ${DISTDIR}/\1 . \&\& \\|' \
		${WRKSRC}/Makefile

post-install:
	# link installed soundfonts to the standard location for convenience of other apps
	@${MKDIR} ${STAGEDIR}${SOUNDFONT_DIR}
	@for f in ${STAGEDIR}${PREFIX}/lib/lv2/*.lv2/FluidPlug.sf2; do \
		${RLN} $$f ${STAGEDIR}${SOUNDFONT_DIR}/$$(${ECHO} $$f | ${SED} -E 's|.*/lib/lv2/([[:alnum:]_]+)\.lv2/FluidPlug\.sf2|\1.sf2|');  \
	done

.include "Makefile.list"
.include <bsd.port.mk>
