PORTNAME=	qmc2
PORTVERSION=	0.243
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	emulators games

MAINTAINER=	agh@riseup.net
COMMENT=	Qt based UNIX MAME frontend
WWW=		https://github.com/qmc2/qmc2-mame-fe

LICENSE=	GPLv2+

BUILD_DEPENDS=	bash>0:shells/bash \
		gawk>0:lang/gawk
RUN_DEPENDS=	libglvnd>0:graphics/libglvnd \
		mame>=0.250:emulators/mame

USES=		compiler:c++11-lang desktop-file-utils gmake gl qt:5 sdl \
		shebangfix tar:bzip2 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	qmc2
GH_PROJECT=	qmc2-mame-fe
USE_GL=		gl glu
USE_QT=		buildtools core declarative gui multimedia network opengl qmake \
		script scripttools sql svg testlib webkit widgets xml \
		xmlpatterns
USE_SDL=	sdl2
USE_XORG=	x11 xmu

SHEBANG_FILES=	scripts/cleanup-category-ini.sh \
		scripts/generate-option-lists.sh \
		scripts/make-man-pages.sh \
		scripts/plugin_helper.sh \
		scripts/romalyzer.pl \
		scripts/sdl-defines.sh \
		scripts/sdl-includepath.sh \
		scripts/sdl-libs.sh \
		scripts/sdl-version.sh \
		scripts/strip-png-headers.sh

MAKE_ARGS=	ARCH="${OPSYS}" \
		CC="${CC}" \
		CC_FLAGS="${CFLAGS} -DUSE_FILE32API" \
		CXX="${CXX}" \
		CXX_FLAGS="${CXXFLAGS} -DUSE_FILE32API" \
		DATADIR="${DATADIR}" \
		LINK="${CXX}" \
		MAKE="${MAKE_CMD}" \
		PHONON="0" \
		QMAKE="${QMAKE}" \
		QTDIR="${PREFIX}" \
		SYSCONFDIR="${PREFIX}/etc"

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
	@${REINPLACE_CMD} -e 's|DATADIR/qmc2|${DATADIR}|g' \
		${WRKSRC}/inst/*.template

do-install:
	(cd ${WRKSRC} && \
		${INSTALL_PROGRAM} qmc2-sdlmame \
		${STAGEDIR}${PREFIX}/bin/qmc2-mame)
	(cd ${WRKSRC}/src/arcade && \
		${INSTALL_PROGRAM} qmc2-arcade \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/src/tools/qchdman && \
		${INSTALL_PROGRAM} qchdman \
		${STAGEDIR}${PREFIX}/bin)

	@${MKDIR} ${STAGEDIR}${DATADIR}
.for data in img lng opt
	(cd ${WRKSRC}/data && \
		${COPYTREE_SHARE} ${data} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_MAN} ${WRKSRC}/data/doc/man/qchdman.6.gz \
		${STAGEDIR}${MANPREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/data/doc/man/qmc2-arcade.6.gz \
		${STAGEDIR}${MANPREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/data/doc/man/qmc2-main-gui.6.gz \
		${STAGEDIR}${MANPREFIX}/man/man6/qmc2-mame.6.gz

.for dsktop_entry in qchdman.desktop qmc2-arcade.desktop qmc2.desktop
	(cd ${WRKSRC}/inst && \
		${INSTALL_DATA} ${dsktop_entry}.template \
		${STAGEDIR}${LOCALBASE}/share/applications/${dsktop_entry})
.endfor

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/inst && \
		${INSTALL_DATA} qmc2.ini.template \
		${STAGEDIR}${ETCDIR}/qmc2.ini.sample)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/data/doc && \
		${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
