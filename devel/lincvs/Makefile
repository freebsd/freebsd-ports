# New ports collection makefile for:	lincvs
# Date created:				03 December 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	lincvs
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	http://ppprs1.phy.tu-dresden.de/~trogisch/lincvs/download/LinCVS/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0-generic-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Graphical CVS front-end using QT

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_QT_VER=	3
QTDIR?=		${X11BASE}
MAKE_ENV+=      QTDIR=${QTDIR}
ALL_TARGET=	install

pre-build:
	( cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile lincvs.pro )
	
do-install:	  
	${INSTALL_PROGRAM} ${WRKSRC}/LinCVS/lincvs.bin ${PREFIX}/bin/lincvs
	${INSTALL_SCRIPT} ${WRKSRC}/LinCVS/Tools/start-ssh-agent.sh ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/LinCVS/Tools/start-ssh.sh ${PREFIX}/bin	
	${MKDIR} -p ${DOCSDIR}
	${CP} -R ${WRKSRC}/LinCVS/Help/* ${DOCSDIR}
	
.include <bsd.port.mk>
