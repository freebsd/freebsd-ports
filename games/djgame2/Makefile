# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	djgame2
PORTVERSION=	3.2.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/
DISTNAME=	source-${PORTVERSION}

MAINTAINER=	games@FreeBSD.org
COMMENT=	bluedj contains many popular online games

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BROKEN=		Fails to link
DEPRECATED=	Resurrected but not fixed
EXPIRATION_DATE=	2014-11-29

USE_QT4=	gui qt3support qmake_build uic_build rcc_build moc_build svg
USES=		dos2unix zip
DOS2UNIX_FILES=	Base/src/DJGraphicsChessTimerItem.cpp

WRKSRC=		${WRKDIR}/${DISTNAME}
DATADIR=	${PREFIX}/share/djgame2

SUB_FILES=	djgame2.desktop startdjg

post-patch:
	${RM} -f ${WRKSRC}/Hall/HallRes/platform/x11/install
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|g' \
		${WRKSRC}/Base/src/PlayWave.cpp
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/make_linux_output
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE} ${QMAKE_ARGS}|' \
		-e 's|make$$|make -j${MAKE_JOBS_NUMBER}|' \
		${WRKSRC}/make_linux_output
	@${ECHO_CMD} "INCLUDEPATH += ${LOCALBASE}/include" \
		>> ${WRKSRC}/Base/Base.pro
	@${ECHO_CMD} "INCLUDEPATH += ${LOCALBASE}/include" \
		>> ${WRKSRC}/Hall/Hall.pro
	@${CHMOD} a+x ${WRKSRC}/make_linux_output

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./make_linux_output

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/Hall/build; ${TAR} -cf - *) | \
		${TAR}  -xf - -C ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/djgame2.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${WRKDIR}/startdjg ${STAGEDIR}${PREFIX}/bin
	@(cd ${STAGEDIR}${DATADIR} && ${STRIP_CMD} modules/*.so Hall \
		UpdateHall libBase.so.1)

.include <bsd.port.mk>
