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

.include "${MASTERDIR}/Makefile"

LIB_DEPENDS+=	qt2.4:${PORTSDIR}/x11-toolkits/qt23

WRKSRC=		${WRKDIR}/qt-${PORTVERSION}
PATCHDIR=	${.CURDIR}/files
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
