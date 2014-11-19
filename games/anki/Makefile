# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anki
PORTVERSION=	2.0.28
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://ankisrs.net/download/mirror/
DIST_SUBDIR=	python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flashcard trainer with spaced repetition

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:${PORTSDIR}/audio/py-pyaudio \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.4:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>=0:${PORTSDIR}/www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:${PORTSDIR}/www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.4:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_PKGNAMEPREFIX}send2trash>0:${PORTSDIR}/deskutils/py-send2trash

USES=		desktop-file-utils python:2 shared-mime-info shebangfix tar:tgz
SHEBANG_FILES=	tools/build_ui.sh tools/tests.sh
USE_QT4=	network_run webkit_run

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext:run

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^Categories=.*|Categories=Education;Languages;KDE;Qt;Game;|' \
		${WRKSRC}/${PORTNAME}.desktop
	@${REINPLACE_CMD} -e 's|/usr/bin/env python|${PYTHON_CMD}|; \
		s|/usr/share/anki|${DATADIR}|' \
		${WRKSRC}/runanki
	@${REINPLACE_CMD} -e \
		's|/usr/share/anki/locale|${PREFIX}/share/locale|' \
		${WRKSRC}/anki/lang.py
	@${FIND} ${WRKSRC} -name "*.bak" -delete -or -name "*.orig" -delete

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' '/mkdir -p qt-locale/,/cp -av locale/s/^/#/' \
		${WRKSRC}/Makefile
.endif

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

.include <bsd.port.mk>
