# New ports collection makefile for:	Ipe
# Date created:				October 25 2000
# Whom:					bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	Ipe
PORTVERSION=	6.0.p12
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.uu.nl/~otfried/Ipe/
DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/.p/pre/}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	bremner@unb.ca
COMMENT=	Extensible drawing editor

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

BROKEN=		Unfetchable

USE_GHOSTSCRIPT_RUN=	yes

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_QT_VER=	3
MAKE_ENV+=	QTDIR=${QTDIR}
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/libexec/ipe/${PORTVERSION:S/.p/pre/} %%PREFIX%%/lib
NO_FILTER_SHLIBS=	1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
# the problem is a little more subtle, really. It requires gcc 3
USE_GCC=	3.4
BROKEN=		"Does not compile"
.endif

QTDIR?=		${X11BASE}
QMAKE?=		${LOCALBASE}/bin/qmake

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

.if !defined(WITH_BROWSER)
	@${ECHO} ""
	@${ECHO} "      Define WITH_BROWSER=myBrowser to use"
	@${ECHO} "      myBrowser to browse ipe help instead of mozilla"
	@${ECHO} ""
.endif

WITH_BROWSER?=mozilla

# This is my feeble attempt at making qmake play nice with FreeBSD.
# If you change a variable, you _must_ reconfigure.
# If it is not on this list, it will _not_ be propagated.
do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${QMAKE} -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		"PREFIX=${PREFIX}"  "WWWBROWSER=${WITH_BROWSER}" \
		"CC=${CC}" "CXX=${CXX}" "LINK=${CXX}" "LINK_SHLIB=${CXX}" \
		"LOCALBASE=${LOCALBASE}" main.pro

.include <bsd.port.post.mk>
