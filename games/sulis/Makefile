PORTNAME=	sulis
DISTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	games

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	af773b9f09753ea8614ac82dd8033c870a5a779c.patch:-p1 \
		fda9fbe830c0db6fbba153f3c2de34ccebf4630f.patch:-p1

MAINTAINER=	alster@vinterdalen.se
COMMENT=	Turn based tactical RPG with several campaigns, written in Rust
WWW=		https://www.sulisgame.com/ \
		https://github.com/Grokmoo/sulis/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/docs/GPLv3-LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		cargo dos2unix
DOS2UNIX_REGEX=	.*\.(rs|toml|yml)
USE_GITHUB=	yes
GH_ACCOUNT=	Grokmoo

CARGO_BUILD_ARGS=	--workspace	# to also build the editor
CARGO_INSTALL=		no

PORTDATA=	campaigns/* data/* mods/*

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/config.sample.yml
	${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g' ${WRKSRC}/sulis_core/src/config.rs

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "campaigns data mods" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/config.sample.yml ${STAGEDIR}${ETCDIR}/config.yml.sample
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/main ${STAGEDIR}${PREFIX}/bin/sulis
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/editor ${STAGEDIR}${PREFIX}/bin/sulis-editor

.include <bsd.port.mk>
