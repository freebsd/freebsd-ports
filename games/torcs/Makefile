# Created by: thierry@pompo.net

PORTNAME=	torcs
DISTVERSION=	1.3.7
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/all-in-one/${PORTVERSION}

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Free, open-source racing car simulator

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis
RUN_DEPENDS=	bash:shells/bash

MAKE_JOBS_UNSAFE=	yes

USES=		compiler:c++11-lang cpe gl gmake openal:al,alut shebangfix \
		tar:bzip2 xorg
CPE_VENDOR=	bernhard_wymann
SHEBANG_FILES=	src/tools/accc/accc.in src/tools/nfsperf/nfsperf.in \
		src/tools/texmapper/texmapper.in src/tools/nfs2ac/nfs2ac.in \
		src/tools/trackgen/trackgen.in \
		src/modules/telemetry/telemetry.sh robotgen
USE_CXXSTD=	c++11
USE_XORG=	xrender xmu ice xext x11 xxf86vm xrandr xi xt sm
USE_GL=		glut glu gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ALL_TARGET=	default
INSTALL_TARGET=	install datainstall
INSTDIR=	${PREFIX}/share/games/${PORTNAME}

PORTDOCS=	faq.html

BASH2FIX=	src/linux/torcs.in Make-default.mk

STRIPFILES=	drivers/berniw/berniw.so \
		drivers/berniw2/berniw2.so \
		drivers/berniw3/berniw3.so \
		drivers/bt/bt.so \
		drivers/damned/damned.so \
		drivers/human/human.so \
		drivers/inferno/inferno.so \
		drivers/inferno2/inferno2.so \
		drivers/lliaw/lliaw.so \
		drivers/olethros/olethros.so \
		drivers/sparkle/sparkle.so \
		drivers/tita/tita.so \
		lib/libclient.so \
		lib/libconfscreens.so \
		lib/liblearning.so \
		lib/libmusicplayer.so \
		lib/libraceengine.so \
		lib/libracescreens.so \
		lib/librobottools.so \
		lib/libtgf.so \
		lib/libtgfclient.so \
		lib/libtxml.so \
		modules/graphic/ssggraph.so \
		modules/simu/simuv2.so \
		modules/telemetry/telemetry.so \
		modules/track/track.so

DESKTOP_ENTRIES=	"TORCS" \
			"The Open Racing Car Simulator" \
			"${INSTDIR}/Ticon.png" \
			"torcs" \
			"Game;Simulation;" \
			false

OPTIONS_DEFINE=	DOCS

EMPTYDIR=	champ dtmrace endrace ncrace practice quickrace

# shebangfix does not catch these two (not at top of file):
post-patch:
.for FILE in ${BASH2FIX}
	@${REINPLACE_CMD} -E -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
	    ${WRKSRC}/${FILE}
.endfor

post-build:
.for FILE in ${STRIPFILES}
	${STRIP_CMD} ${WRKSRC}/export/${FILE}
.endfor

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/faq/|} ${STAGEDIR}${DOCSDIR}
	# strip simuv2.so as reported by Q/A tests
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/torcs/modules/simu/simuv2.so

.for ed in ${EMPTYDIR}
	${TOUCH} ${STAGEDIR}${INSTDIR}/results/${ed}/.keep_me
.endfor

.include <bsd.port.mk>
