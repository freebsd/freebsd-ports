PORTNAME=	qmc2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.243-14
DISTVERSIONSUFFIX=	-g112724d69
CATEGORIES=	emulators games

MAINTAINER=	agh@riseup.net
COMMENT=	Qt5 graphical interface for MAME
WWW=		https://github.com/qmc2/qmc2-mame-fe

LICENSE=	GPLv2+

BUILD_DEPENDS=	bash>0:shells/bash \
		gawk>0:lang/gawk
LIB_DEPENDS=	libminizip-ng.so:archivers/minizip-ng
RUN_DEPENDS=	libglvnd>0:graphics/libglvnd \
		mame>=0.259:emulators/mame

USES=		compiler:c++11-lang libarchive gl gmake pkgconfig qt:5 sdl \
		shebangfix tar:bzip2 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	qmc2
GH_PROJECT=	qmc2-mame-fe
USE_GL=		gl glu
USE_QT=		buildtools core declarative gui location multimedia network \
		opengl printsupport qmake script scripttools sql svg testlib \
		webchannel webengine widgets xml xmlpatterns
USE_SDL=	sdl2
USE_XORG=	x11 xmu

SHEBANG_FILES=	scripts/cleanup-category-ini.sh \
		scripts/generate-option-lists.sh scripts/make-man-pages.sh \
		scripts/plugin_helper.sh scripts/romalyzer.pl \
		scripts/sdl-defines.sh scripts/sdl-includepath.sh \
		scripts/sdl-libs.sh scripts/sdl-version.sh \
		scripts/strip-png-headers.sh

MAKE_ARGS=	ARCH="${OPSYS}" \
		CC="${CC}" \
		CC_FLAGS="${CFLAGS} -DUSE_FILE32API" \
		CXX="${CXX}" \
		CXX_FLAGS="${CXXFLAGS} -DUSE_FILE32API" \
		DATADIR="${DATADIR}" \
		LIBARCHIVE=1 \
		MAKE="${MAKE_CMD}" \
		QMAKE="${QMAKE}" \
		QTDIR="${PREFIX}" \
		SYSCONFDIR="${ETCDIR}" \
		SYSTEM_MINIZIP=1 \
		SYSTEM_ZLIB=1

ALL_TARGET=	all arcade tools
CFLAGS_aarch64=	-march=armv8-a+crc+crypto

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_DESC=	Comprehensive qmc2 documentaion

DOCS_ALL_TARGET=	doc
DOCS_PORTDOCS=		html

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300000
EXTRA_PATCHES=	${PATCHDIR}/extra-scripts-sdl-includepaths
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}/|g' \
		-e 's|%%DOCSDIR%%|${DOCSDIR}/|g' \
		${WRKSRC}/inst/*.template

do-install:
	${FIND} ${WRKSRC} -type f -name "q*" -perm -o=+x -exec ${INSTALL_PROGRAM} \
		{} ${STAGEDIR}${PREFIX}/bin/ \;
	${RLN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-sdlmame ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for DATA in cat gmn img js lng opt swn
	(cd ${WRKSRC}/data && \
		${COPYTREE_SHARE} ${DATA} ${STAGEDIR}${DATADIR} "! -name dirinfo.txt")
.endfor
	${INSTALL_MAN} ${WRKSRC}/data/doc/man/*.6.gz \
		${STAGEDIR}${PREFIX}/share/man/man6
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man6/${PORTNAME}-main-gui.6.gz \
		${STAGEDIR}${PREFIX}/share/man/man6/${PORTNAME}.6.gz
.for DESKTOP_ENTRY in qchdman.desktop qmc2-arcade.desktop qmc2.desktop
	${INSTALL_DATA} ${WRKSRC}/inst/${DESKTOP_ENTRY}.template \
		${STAGEDIR}${PREFIX}/share/applications/${DESKTOP_ENTRY}
.endfor
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/inst/qmc2.ini.template \
		${STAGEDIR}${ETCDIR}/qmc2.ini.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/data/doc && \
		${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
