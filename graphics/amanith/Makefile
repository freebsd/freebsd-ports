# New ports collection makefile for:	amanith
# Date created:		2006-09-01
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amanith
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.amanith.org/download/files/ \
		http://louhi.kempele.fi/~skyostil/projects/pyamanith/dist/
DISTNAME=	${PORTNAME:S/$/_/}${PORTVERSION:S/.//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	C++ CrossPlatform framework designed for 2d & 3d vector graphics

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

USE_QT_VER=	3
USE_GL=		yes
USE_GMAKE=	yes
USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC="${QMAKESPEC}" \
		AMANITHDIR="${AMANITHDIR}"

QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
QMAKECMD=	qmake
AMANITHDIR=	${WRKSRC}
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|3rdpart||' ${WRKSRC}/amanith.pro

post-extract:
	@${RMDIR} ${WRKSRC}/include/${PORTNAME}/3d

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKECMD} ${WRKSRC}/amanith.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libamanith.so.1.0.0 ${PREFIX}/lib/libamanith.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/libfontimpexp.so.1.0.0 ${PREFIX}/lib/libfontimpexp.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/libjpegimpexp.so.1.0.0 ${PREFIX}/lib/libjpegimpexp.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/libpngimpexp.so.1.0.0 ${PREFIX}/lib/libpngimpexp.so.1

.	for FILE in libamanith libfontimpexp libjpegimpexp libpngimpexp
		cd ${PREFIX}/lib && \
			${LN} -s ${FILE}.so.1  ${FILE}.so
.	endfor

	${MKDIR} ${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/include/${PORTNAME} && \
		${FIND}	* -type d -exec ${MKDIR} "${PREFIX}/include/${PORTNAME}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/include/${PORTNAME}/{}" \;

.	for DIRE in fonts jpeg png
	cd ${WRKSRC}/plugins/${DIRE} && \
		${INSTALL_DATA} *.h ${PREFIX}/include/${PORTNAME}
.	endfor

.include <bsd.port.post.mk>
