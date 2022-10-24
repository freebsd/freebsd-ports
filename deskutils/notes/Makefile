PORTNAME=	notes
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Beautiful and powerful note-taking application
WWW=		https://www.get-notes.com/

LICENSE=	MPL20

USES=		qmake qt:5
USE_QT=		buildtools:build concurrent core gui network sql widgets

USE_GITHUB=	yes
GH_ACCOUNT=	nuttyartist alex-spataru:qsu b00f:qas pbek:qmdte
GH_PROJECT=	QSimpleUpdater:qsu qautostart:qas qmarkdowntextedit:qmdte
GH_TAGNAME=	62567ee:qsu 5be8fea:qas f69e622:qmdte
GH_SUBDIR=	3rdParty/QSimpleUpdater:qsu 3rdParty/qautostart:qas \
		3rdParty/qmarkdowntextedit:qmdte

post-patch:
	@${REINPLACE_CMD} -e '/^OBJECTS_DIR = obj/d' ${WRKSRC}/src/Notes.pro
	@${REINPLACE_CMD} -e 's,Q_OS_LINUX,Q_OS_UNIX,' \
		${WRKSRC}/src/updaterwindow.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/Notes \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/packaging/linux/common/*.desktop \
		${STAGEDIR}${PREFIX}/share/applications
.for n in 16 22 24 32 48 64 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} \
	    ${WRKSRC}/packaging/linux/common/icons/${n}x${n}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} \
	    ${WRKSRC}/packaging/linux/common/icons/scalable/${PORTNAME}.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
