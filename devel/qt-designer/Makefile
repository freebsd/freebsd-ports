# New ports collection makefile for:	Qt Designer
# Date created:				Sat Feb  3 23:04:41 EST 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	qt-designer
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI C++ IDE based on QT

LIB_DEPENDS+=	qt2.4:${PORTSDIR}/x11-toolkits/qt23

MASTERDIR=	${.CURDIR}/../../x11-toolkits/qt23

CONFLICTS=	qt-3.*
BROKEN=		"fails to install"

WRKSRC=		${WRKDIR}/qt-${PORTVERSION}
PATCH_WRKSRC=	${WRKSRC}
PKGDIR=		${.CURDIR}
MAKE_ENV=	QTDIR=${PREFIX} LD_LIBRARY_PATH=${PREFIX}/lib PREFIX=${PREFIX}
ALL_TARGET=	sub-tools
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e "s@-fno-exceptions@& -I${X11BASE}/include/qt2@g" ${CONFIG}

do-build:
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

qt-pre-configure:
	${REINPLACE_CMD} -e 's@\(DESTDIR = \)\$$(QTDIR)/bin@\1../../../bin@' \
		${WRKSRC}/tools/designer/designer/Makefile.in
	${REINPLACE_CMD} -e 's@\(sub-tools: \)sub-src @\1@' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's@\$$\(MAKE\) util@@; s@\$$\(MAKE\) uic@@; \
		s@util \\@designer@g; s@uic \\@@g; \
		s@'"`printf '\t\t'`"'designer@@g' ${WRKSRC}/tools/designer/Makefile.in
	${REINPLACE_CMD} -e 's@getenv( "QTDIR" )@QT_PREFIX@g; \
		s@/tools/designer/templates@/share/qt2/designer/templates@g' \
		${WRKSRC}/tools/designer/designer/newformimpl.cpp

.include "${MASTERDIR}/Makefile"

do-install:
	${MKDIR} ${PREFIX}/share/qt2/designer/templates \
		${PREFIX}/share/doc/qt2/html/designer/arrows \
		${PREFIX}/share/doc/qt2/html/designer/figures
	${INSTALL_PROGRAM} ${WRKSRC}/bin/designer ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tools/designer/templates/* \
		${PREFIX}/share/qt2/designer/templates
	${INSTALL_DATA} ${WRKSRC}/doc/html/designer/*.html \
		${PREFIX}/share/doc/qt2/html/designer
.for IMGDIR in arrows figures
	${INSTALL_DATA} ${WRKSRC}/doc/html/designer/${IMGDIR}/*.png \
		${PREFIX}/share/doc/qt2/html/designer/${IMGDIR}
.endfor
