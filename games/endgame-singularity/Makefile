PORTNAME=	singularity
PORTVERSION=	1.00
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	endgame-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Simulates the life of a true AI
WWW=		http://emhsoft.com/singularity/

LICENSE=	GPLv2+ MIT CC-BY-SA-3.0 NASA AEFONTS BITSTREAM AREV \
		MEMESBRUH03 CC0-1.0
LICENSE_COMB=	multi
LICENSE_NAME_NASA=	NASA Terms of Use
LICENSE_NAME_AEFONTS=	Brian Kent - Aenigma Games & Fonts
LICENSE_NAME_BITSTREAM=	Bitstream Vera Fonts Copyright
LICENSE_NAME_AREV=	Arev Fonts Copyright
LICENSE_NAME_MEMESBRUH03=	memesbruh03 Copyright
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/LICENSE.gpl.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/LICENSE.CC-BY-SA-3.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSE.cc0.txt
LICENSE_PERMS_NASA=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_AEFONTS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_BITSTREAM=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_AREV=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_MEMESBRUH03=	dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

RUN_DEPENDS=	${PYGAME} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}polib>=0:devel/py-polib@${PY_FLAVOR}

USES=		python sdl shebangfix
USE_PYTHON=	autoplist distutils
USE_SDL=	image mixer
PORTDOCS=	AUTHORS.txt Changelog.txt README.txt TODO
NO_ARCH=	yes
SHEBANG_FILES=	singularity/i18n/utils/languages.py

OPTIONS_DEFINE=	MUSIC DOCS
OPTIONS_DEFAULT=	MUSIC

MUSIC_DESC=	Install original music pack
MUSIC_RUN_DEPENDS=	endgame-singularity-music>=006:games/endgame-singularity-music

post-extract:
	@${MV} ${WRKSRC}/singularity/data ${WRKSRC}/

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/data
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/data)
	${INSTALL_DATA} ${WRKSRC}/singularity.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
