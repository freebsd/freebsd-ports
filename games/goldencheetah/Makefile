# Created by: Bert Burgemeister <trebbu@googlemail.com>
# $FreeBSD$

PORTNAME=	GoldenCheetah
PORTVERSION=	3.2
DISTVERSIONPREFIX=	V
PORTREVISION=	7
CATEGORIES=	games

MAINTAINER=	trebbu@googlemail.com
COMMENT=	Training software for cyclists

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN=		fails to build

LIB_DEPENDS=	libical.so:devel/libical \
		libqwtplot3d-qt4.so:math/qwtplot3d-qt4 \
		libkqoauth.so:security/kqoauth
		#vlc-qt4 is deprecated and has been removed
		#libvlc.so:multimedia/vlc-qt4

USE_GITHUB=	yes

DESKTOP_ENTRIES=	"${PORTNAME}" \
			"${COMMENT}" \
			"${DATADIR}/gc.png" \
			"${PORTNAME}" \
			"Education;Sports;" \
			false

USES=		bison gmake qmake qt:4
USE_GL=		gl glu
USE_QT=		corelib gui linguist moc_build network opengl \
		qmake rcc script sql svg uic webkit xml
INFO=		GC3-FAQ GC3-Release GC31-Release

OPTIONS_DEFINE=	DOCS

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
	${INSTALL_DATA} ${WRKSRC}/doc/user/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
