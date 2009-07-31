# New ports collection makefile for:	Ipe
# Date created:				October 25 2000
# Whom:					bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	ipe
PORTVERSION=	6.0.p23
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://ipe.compgeom.org/ \
		http://tclab.kaist.ac.kr/~otfried/Ipe/
DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/.p/pre/}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible drawing editor

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_GHOSTSCRIPT_RUN=	yes

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_QT_VER=	3
MAKE_ENV+=	QTDIR=${QTDIR}
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib
MAN1=		figtoipe.1 ipe.1 ipe5toxml.1 ipetoipe.1 ipetopng.1

.include <bsd.port.pre.mk>

QTDIR?=		${QT_PREFIX}
QMAKE?=		${LOCALBASE}/bin/qmake

pre-fetch:
.if !defined(WITH_TEXMF_PREFIX)
	@${ECHO} ""
	@${ECHO} "      Define WITH_TEXMF_PREFIX=somewhere"
	@${ECHO} "      if your tetex type1 fonts are somewhere non-standard"
	@${ECHO} ""
.endif

.if !defined(WITH_BROWSER)
	@${ECHO} ""
	@${ECHO} "      Define WITH_BROWSER=myBrowser to use"
	@${ECHO} "      myBrowser to browse ipe help instead of mozilla"
	@${ECHO} ""
.endif

WITH_BROWSER?=mozilla
WITH_TEXMF_PREFIX?=	${PREFIX}/share/texmf-dist

# This is my feeble attempt at making qmake play nice with FreeBSD.
# If you change a variable, you _must_ reconfigure.
# If it is not on this list, it will _not_ be propagated.
do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${QMAKE} -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		"PREFIX=${PREFIX}"  "WWWBROWSER=${WITH_BROWSER}" \
		"CC=${CC}" "CXX=${CXX}" "LINK=${CXX}" "LINK_SHLIB=${CXX}" \
		"LOCALBASE=${LOCALBASE}" main.pro

post-install:
	cd ${WRKSRC}/.. && mkdir -p ${DATADIR} && \
	sed s@/usr/share/texmf@${WITH_TEXMF_PREFIX}@ \
	< tetex-fontmap.xml >  	${DATADIR}/fontmap.xml

.include <bsd.port.post.mk>
