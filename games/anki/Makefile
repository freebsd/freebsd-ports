# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anki
DISTVERSION=	2.0.50
CATEGORIES=	games python
MASTER_SITES=	https://apps.ankiweb.net/downloads/current/
DISTNAME=	anki-${PORTVERSION}-source
DIST_SUBDIR=	python

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Flashcard trainer with spaced repetition

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lame:audio/lame \
		mplayer:multimedia/mplayer \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>0:www/py-beautifulsoup32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>0:deskutils/py-send2trash@${PY_FLAVOR}

USES=		desktop-file-utils pyqt:4 python:2.7 shared-mime-info shebangfix tar:tgz
SHEBANG_FILES=	tools/build_ui.sh tools/tests.sh anki/anki runanki
USE_PYQT=	network_run webkit_run
USE_QT4=	network_run webkit_run
NO_ARCH=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-runtime gettext-tools

WRKSRC=		${WRKDIR}/anki-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -i '' 's|/usr/share/anki|${DATADIR}|' \
	       	${WRKSRC}/runanki
	@${REINPLACE_CMD} -i '' 's|"qt_" + lang, dir|"qt_" + lang, "${DATADIR}/locale"|' \
	       	${WRKSRC}/aqt/__init__.py
	@${REINPLACE_CMD} -i '' \
		's|/usr/share/anki/locale|${PREFIX}/share/locale|; \
		s|/usr/local/share/anki/bin/locale|${PREFIX}/share/locale|' \
		${WRKSRC}/anki/lang.py

post-patch-NLS-off:
	@${REINPLACE_CMD} -i '' '/mkdir -p qt-locale/,/cp -av locale/s/^/#/' \
		${WRKSRC}/Makefile

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

.include <bsd.port.mk>
