PORTNAME=	torcs
DISTVERSION=	1.3.10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/all-in-one/${DISTVERSION}

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Free, open-source racing car simulator
WWW=		https://torcs.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
LIB_DEPENDS=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang cpe gl gmake localbase:ldflags \
		openal:al,alut shebangfix tar:bzip2 xorg
CPE_VENDOR=	bernhard_wymann
USE_CXXSTD=	c++11
USE_GL=		gl glu glut
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xi xmu xrandr xrender xt xxf86vm

SHEBANG_FILES=	src/tools/accc/accc.in src/tools/nfsperf/nfsperf.in \
		src/tools/texmapper/texmapper.in src/tools/nfs2ac/nfs2ac.in \
		src/tools/trackgen/trackgen.in \
		src/modules/telemetry/telemetry.sh robotgen

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	default
INSTALL_TARGET=	install datainstall

DATADIR=	${PREFIX}/share/games/${PORTNAME}

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

OPTIONS_DEFINE=	DOCS

# shebangfix does not catch these two (not at top of file):
post-patch:
	@${REINPLACE_CMD} -E -e "s|/bin/bash|${LOCALBASE}/bin/bash|" \
	    ${src/linux/torcs.in Make-default.mk:L:S|^|${WRKSRC}/|}
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/torcs.desktop

do-install-DOCS-on:
	(cd ${WRKSRC}/doc/userman && \
		${COPYTREE_SHARE} "how_to_drive.html images" ${STAGEDIR}${DOCSDIR})

post-install:
	${STRIP_CMD} ${STRIPFILES:S|^|${STAGEDIR}${PREFIX}/lib/torcs/|}
	${INSTALL_DATA} ${WRKSRC}/torcs.desktop ${STAGEDIR}${DESKTOPDIR}
	${TOUCH} ${champ dtmrace endrace ncrace practice quickrace \
		:L:C|^(.*)$|${STAGEDIR}${DATADIR}/results/\1/.keep_me|}

.include <bsd.port.mk>
