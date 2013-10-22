# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	djgame2
PORTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.bluedj.com/download/src/
DISTNAME=	source-${PORTVERSION}
#EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	bluedj contains many popular online games

NO_BUILD=	yes
USE_ZIP=	yes
USE_QT4=	gui qt3support qmake_build uic_build rcc_build moc_build svg

QMAKE?=		qmake-qt4
QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

WRKSRC=		${WRKDIR}/${DISTNAME}
DATADIR=	${PREFIX}/share/djgame2

SUB_FILES=	djgame2.desktop startdjg

NO_STAGE=	yes
post-patch:
	${RM} -f ${WRKSRC}/Hall/HallRes/platform/x11/install
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|g' \
		${WRKSRC}/Base/src/PlayWave.cpp
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/make_linux_output
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE}|' \
		${WRKSRC}/make_linux_output
	@${ECHO_CMD} "INCLUDEPATH += ${LOCALBASE}/include" \
		>> ${WRKSRC}/Base/Base.pro
	@${ECHO_CMD} "INCLUDEPATH += ${LOCALBASE}/include" \
		>> ${WRKSRC}/Hall/Hall.pro
	@${CHMOD} a+x ${WRKSRC}/make_linux_output

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./make_linux_output

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/Hall/build; ${TAR} -cf - *) | \
		${TAR}  -xf - -C ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/djgame2.desktop ${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${WRKDIR}/startdjg ${PREFIX}/bin

.include <bsd.port.mk>
