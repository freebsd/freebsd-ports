PORTNAME=	notes
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	deskutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	eda71ecf0a9cd7122e8bacf895fb8214dcecb503.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Beautiful and powerful note-taking application
WWW=		https://www.get-notes.com/

LICENSE=	MPL20

USES=		qmake qt:5
USE_QT=		buildtools:build concurrent core gui network sql widgets

USE_GITHUB=	yes
GH_ACCOUNT=	nuttyartist b00f:qas pbek:qmdte
GH_PROJECT=	qautostart:qas qmarkdowntextedit:qmdte
GH_TAGNAME=	5be8fea:qas f69e622:qmdte
GH_SUBDIR=	3rdParty/qautostart:qas 3rdParty/qmarkdowntextedit:qmdte

post-patch:
	@${RM} ${WRKSRC}/src/updaterwindow.*

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
