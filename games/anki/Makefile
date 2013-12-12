# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anki
PORTVERSION=	2.0.19
CATEGORIES=	games python
MASTER_SITES=	http://ankisrs.net/download/mirror/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Flashcard trainer with spaced repetition

LICENSE=	AGPLv3

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

USES=		desktop-file-utils shared-mime-info
USE_PYTHON=	2.7
USE_QT4=	network_run webkit_run

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext:run

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|' \
		${WRKSRC}/runanki
	@${REINPLACE_CMD} -e 's|/usr/share/anki/locale|${PREFIX}/share/locale/|' \
		${WRKSRC}/anki/lang.py
	@${REINPLACE_CMD} \
		-e 's|^Categories=.*|Categories=Education;Languages;KDE;Qt;Game;|' \
		${WRKSRC}/${PORTNAME}.desktop
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/runanki ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.for d in anki aqt designer oldanki tests tools
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/locale/qt* ${STAGEDIR}${DATADIR}/locale/

.if ${PORT_OPTIONS:MNLS}
.  for f in af ar az bg bn ca cs da de el en_GB eo es et eu fa fi fr gl gu he \
	hu it ja km ko lt lv mn mr ms nb nl no oc pl pt pt_BR ro ru sk sl sr \
	sv th tlh tr uk vi wo zh_CN zh_HK zh_TW
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${f}/LC_MESSAGES && \
		${INSTALL_DATA} ${WRKSRC}/locale/${f}/LC_MESSAGES/${PORTNAME}.mo \
	${STAGEDIR}${PREFIX}/share/locale/${f}/LC_MESSAGES/${PORTNAME}.mo
.  endfor
.endif

	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages/

.for p in *.png *.xpm
	${INSTALL_DATA} ${WRKSRC}/${p} \
		${STAGEDIR}${PREFIX}/share/pixmaps/
.endfor

.include <bsd.port.mk>
