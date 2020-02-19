# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anki
DISTVERSION=	2.1.16
CATEGORIES=	games python
MASTER_SITES=	https://apps.ankiweb.net/downloads/archive/
DISTNAME=	anki-${PORTVERSION}-source
DIST_SUBDIR=	python

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Flashcard trainer with spaced repetition

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lame:audio/lame \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>0:deskutils/py-send2trash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:5 python:3.6+ shebangfix tar:tgz
USE_PYQT=	core_run gui_run printsupport_run sip_run webengine_run widgets_run

NO_ARCH=	yes
SHEBANG_FILES=	tools/runanki.system.in
WRKSRC=		${WRKDIR}/anki-${PORTVERSION}

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	MPV
OPTIONS_GROUP=		PLAYER
OPTIONS_GROUP_PLAYER=	MPLAYER MPV
OPTIONS_SUB=		yes

MPV_DESC=	mpv media player support

MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv

NLS_USES=	gettext-runtime gettext-tools

post-patch:
	@${REINPLACE_CMD} -i '' \
		's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/anki/lang.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete

post-patch-NLS-off:
	@${REINPLACE_CMD} -i '' '/locale/s/^/#/' \
		${WRKSRC}/Makefile

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/runanki.system ${STAGEDIR}${PREFIX}/bin/anki

.include <bsd.port.mk>
