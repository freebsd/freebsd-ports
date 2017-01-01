# Created by: Bert Burgemeister <trebbu@googlemail.com>
# $FreeBSD$

PORTNAME=	GoldenCheetah
PORTVERSION=	3.2
DISTVERSIONPREFIX=	V
CATEGORIES=	games

MAINTAINER=	trebbu@googlemail.com
COMMENT=	Training software for cyclists

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libical.so:devel/libical \
		libqwtplot3d-qt4.so:math/qwtplot3d-qt4 \
		libkqoauth.so:security/kqoauth \
		libvlc.so:multimedia/vlc-qt4

USE_GITHUB=	yes

DESKTOP_ENTRIES=	"${PORTNAME}" \
			"${COMMENT}" \
			"${DATADIR}/gc.png" \
			"${PORTNAME}" \
			"Education;Sports;" \
			false

USES=		bison gmake qmake
USE_GL=		gl glu
USE_QT4=	corelib gui linguist moc_build network opengl \
		qmake rcc script sql svg uic webkit xml
INFO=		GC3-FAQ GC3-Release GC31-Release

post-extract:
	${CP} ${WRKSRC}/src/gcconfig.pri.in ${WRKSRC}/src/gcconfig.pri
	${CP} ${WRKSRC}/qwt/qwtconfig.pri.in ${WRKSRC}/qwt/qwtconfig.pri

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/images/gc.png \
		${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/user/*.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/user/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
