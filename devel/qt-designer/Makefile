# New ports collection makefile for:	Qt Designer
# Date created:				Sat Feb  3 23:04:41 EST 2001
# Whom:					will
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../x11-toolkits/qt23

PORTNAME=	qt-designer
CATEGORIES=	devel

post-patch:
	${PERL} -pi -e "s@-fno-exceptions@-fno-exceptions -I${X11BASE}/include/qt2@g" ${CONFIG}

do-build:
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

qt-pre-configure:
	${PERL} -pi -e 's@DESTDIR = \$$\(QTDIR\)/bin@DESTDIR = ../../../bin@g' \
		${WRKSRC}/tools/designer/designer/Makefile.in
	${PERL} -pi -e 's@sub-tools: sub-src @sub-tools: @g' ${WRKSRC}/Makefile
	${PERL} -pi -e "s@\$$(MAKE) util@@g; s@\$$(MAKE) uic@@g; \
			s@util \\\@designer@g; s@uic \\\@@g; \
			s@\t\tdesigner@@g" ${WRKSRC}/tools/designer/Makefile.in
	${PERL} -pi -e "s@getenv\( \"QTDIR\" \)@QT_PREFIX@g; \
		s@/tools/designer/templates@/share/qt2/designer/templates@g" \
		${WRKSRC}/tools/designer/designer/newformimpl.cpp

.include "${MASTERDIR}/Makefile"

LIB_DEPENDS+=	qt2.4:${PORTSDIR}/x11-toolkits/qt23

WRKSRC=		${WRKDIR}/qt-${PORTVERSION}
PATCH_WRKSRC=	${WRKSRC}
PKGDIR=		${.CURDIR}
MAKE_ENV=	QTDIR=${PREFIX} LD_LIBRARY_PATH=${PREFIX}/lib PREFIX=${PREFIX}
ALL_TARGET=	sub-tools

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
