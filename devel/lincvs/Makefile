# New ports collection makefile for:	lincvs
# Date created:				03 December 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	lincvs
PORTVERSION=	1.3.1
CATEGORIES=	devel kde
MASTER_SITES=	http://ppprs1.phy.tu-dresden.de/~trogisch/lincvs/download/20_LinCVS/hn_${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0-generic-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical CVS front-end using QT

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_QT_VER=	3
QTDIR?=		${X11BASE}
MAKE_ENV+=      QTDIR=${QTDIR}
ALL_TARGET=	install
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/src/main.cpp \
		${WRKSRC}/src/lincvs.cpp

pre-build:
	( cd ${WRKSRC} && qmake -spec freebsd-g++ -o Makefile lincvs.pro )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/LinCVS/lincvs.bin ${PREFIX}/bin/lincvs
	${INSTALL_SCRIPT} ${WRKSRC}/LinCVS/Tools/start-ssh-agent.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/LinCVS/Tools/start-ssh.sh ${PREFIX}/bin
	${MKDIR} ${DATADIR}/translation
	${INSTALL_DATA} ${WRKSRC}/ts/*.qm ${DATADIR}/translation
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/LinCVS/Help/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
