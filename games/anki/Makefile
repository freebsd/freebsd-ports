# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anki
PORTVERSION=	2.0.7
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://ankisrs.net/download/mirror/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Flashcard trainer with spaced repetition

LICENSE=	AGPLv3 # (or later)

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pyaudio>0:${PORTSDIR}/audio/py-pyaudio \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy>0:${PORTSDIR}/databases/py-sqlalchemy \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=4.4:${PORTSDIR}/net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=3.2:${PORTSDIR}/www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:${PORTSDIR}/www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}qt4-webkit>=4.4:${PORTSDIR}/www/py-qt4-webkit

USE_PYTHON=	-2.7
USE_QT4=	network_run webkit_run
USE_GETTEXT=	run

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|' \
		${WRKSRC}/runanki

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/runanki ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DATADIR}
.for i in anki aqt designer locale oldanki tests tools
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${DATADIR})
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	@${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${DESKTOPDIR}
	@${MKDIR} ${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.xml \
		${PREFIX}/share/mime/packages
	@${MKDIR} ${PREFIX}/share/pixmaps
.for p in *.png *.xpm
	${INSTALL_DATA} ${WRKSRC}/${p} \
		${PREFIX}/share/pixmaps
.endfor
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
