# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anki
PORTVERSION=	2.0.32
CATEGORIES=	games python
MASTER_SITES=	http://ankisrs.net/download/mirror/
DIST_SUBDIR=	python

MAINTAINER=	trebbu@googlemail.com
COMMENT=	Flashcard trainer with spaced repetition

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lame:audio/lame \
		mplayer:multimedia/mplayer \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy07>0:databases/py-sqlalchemy07 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.4:net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>=0:www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.4:www/py-qt4-webkit \
		${PYTHON_PKGNAMEPREFIX}send2trash>0:deskutils/py-send2trash

USES=		desktop-file-utils python:2 shared-mime-info shebangfix tar:tgz
SHEBANG_FILES=	tools/build_ui.sh tools/tests.sh
USE_QT4=	network_run webkit_run
OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-runtime gettext-tools

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|; \
		s|/usr/share/anki|${DATADIR}|' \
		${WRKSRC}/runanki
	@${REINPLACE_CMD} -e \
		's|/usr/share/anki/locale|${PREFIX}/share/locale|' \
		${WRKSRC}/anki/lang.py

post-patch-NLS-off:
	@${REINPLACE_CMD} -i '' '/mkdir -p qt-locale/,/cp -av locale/s/^/#/' \
		${WRKSRC}/Makefile

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

.include <bsd.port.mk>
