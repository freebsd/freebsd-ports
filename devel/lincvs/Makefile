# New ports collection makefile for:	lincvs
# Date created:				03 December 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	lincvs
PORTVERSION=	1.4.2
CATEGORIES=	devel kde
MASTER_SITES=	http://lincvs.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0-generic-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvioc@gmail.com
COMMENT=	Graphical CVS front-end using QT

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_QT_VER=	3
QTDIR?=		${X11BASE}
MAKE_ENV+=	QTDIR=${QTDIR} QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
ALL_TARGET=	install

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/src/main.cpp \
		${WRKSRC}/src/lincvs.cpp

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake lincvs.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LinCVS/lincvs.bin ${PREFIX}/bin/lincvs
	${INSTALL_SCRIPT} ${WRKSRC}/LinCVS/Tools/launch_emacs.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/LinCVS/Tools/launch_xemacs.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/LinCVS/Tools/start-ssh-agent.sh ${PREFIX}/bin
	${MKDIR} ${DATADIR}/translation
	${INSTALL_DATA} ${WRKSRC}/ts/*.qm ${DATADIR}/translation
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/LinCVS/Help/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
