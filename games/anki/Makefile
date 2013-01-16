# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anki
PORTVERSION=	2.0.4
CATEGORIES=	games
MASTER_SITES=	http://ankisrs.net/download/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
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
	@${SED} -e 's|/usr/share/|${PYTHON_SITELIBDIR}/|' \
		< ${WRKSRC}/runanki > ${WRKDIR}/${PORTNAME}

do-build:
	@-${PYTHON_CMD} -m compileall -f ${WRKSRC}
	@-${PYTHON_CMD} -O -m compileall -f ${WRKSRC}

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} ${PORTNAME} ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 ${MANPREFIX}/man/man1)
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
.for i in anki aqt designer locale oldanki tests tools
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} \
		${PYTHON_SITELIBDIR}/${PORTNAME})
.endfor
	@${MKDIR} ${DESKTOPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} anki.desktop \
		${DESKTOPDIR})
	@${MKDIR} ${PREFIX}/share/mime/packages
	(cd ${WRKSRC} && ${INSTALL_DATA} anki.xml \
		${PREFIX}/share/mime/packages)
	@${MKDIR} ${PREFIX}/share/pixmaps
	(cd ${WRKSRC} && ${INSTALL_DATA} anki.png anki.xpm \
		${PREFIX}/share/pixmaps)
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
