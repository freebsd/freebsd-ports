PORTNAME=		gtultra
DISTVERSIONPREFIX=	v
DISTVERSION=		1.5.5
CATEGORIES=		audio

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Music tracker for the C64, fork of goattracker
WWW=		https://github.com/jpage8580/GTUltra

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/copying

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		gmake pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	jpage8580
GH_PROJECT=	GTUltra
USE_SDL=	sdl2

MAKEFILE=	makefile

DESKTOP_ENTRIES=	"GTUltra" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/gtultra.ico" \
			"gtultra" \
			"" \
			false

BUILD_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
.for p in gtultra mod2sng2 ss2stereo
		${INSTALL_PROGRAM} ${WRKSRC}/linux/${p} \
			${STAGEDIR}${PREFIX}/bin
.endfor
# Avoid conflict with original goattracker:
.for p in gt2reloc ins2snd2
		${INSTALL_PROGRAM} ${WRKSRC}/linux/${p} \
			${STAGEDIR}${PREFIX}/bin/${p}u
.endfor
		${INSTALL_DATA} ${WRKSRC}/src/gt2stereo_2.ico \
			${STAGEDIR}${PREFIX}/share/pixmaps/gtultra.ico

post-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in readme.txt GTUltra.pdf
		${INSTALL_MAN} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		(cd ${WRKSRC}/examples && \
			${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
