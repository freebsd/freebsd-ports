# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qcad
PORTVERSION=	3.4.2.0
CATEGORIES=	cad
MASTER_SITES=	http://github.com/${PORTNAME}/${PORTNAME}/archive/${DISTNAME}.tar.gz?dummy=/	\
		https://github.com/${PORTNAME}/${PORTNAME}/archive/${DISTNAME}.tar.gz?dummy=/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		${LOCALBASE}/lib/libopenNURBS.a:${PORTSDIR}/graphics/opennurbs
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

FETCH_ARGS=	-Fpr
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_UNSAFE=yes

USES=		gmake qmake
USE_LDCONFIG=	yes
USE_QT4=	qmake_build codecs-cn codecs-jp codecs-kr codecs-tw corelib \
		designer gui help imageformats moc_build network opengl rcc_build script \
		scripttools sql svg uic_build xml xmlpatterns webkit
USE_GL=		glu

DESKTOP_ENTRIES="QCad"	\
		"" \
		"${DATADIR}/scripts/qcad_icon.png"	\
		"${PREFIX}/bin/qcad-bin"	\
		""	\
		true

.if defined(WITH_DEBUG)
RESDIR=		${WRKSRC}/debug
.else
RESDIR=		${WRKSRC}/release
.endif

SHRLIBS=	qcadcore qcadecmaapi qcadentity qcadgrid qcadgui qcadoperations	\
		qcadsnap qcadspatialindex qcadstemmer spatialindexnavel
STALIBS=	dxflib stemmer
SHRDIR=		fonts libraries patterns plugins scripts ts
QSCRIPTS=	bbox dwg2bmp dwg2pdf dwg2svg
SUB_FILES=	${QSCRIPTS}

pre-configure:
	${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|"	\
		${WRKSRC}/src/core/RSettings.cpp

do-install:
	${INSTALL_PROGRAM} ${RESDIR}/qcad-bin ${STAGEDIR}${PREFIX}/bin/
	${LN} -sf ${PREFIX}/bin/qcad-bin ${STAGEDIR}${PREFIX}/bin/qcad
.for prog in ${QSCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/${prog} ${STAGEDIR}${PREFIX}/bin
.endfor
.for lib in ${SHRLIBS:C|^|lib|:C|$|.so|}
	${INSTALL_LIB} ${RESDIR}/${lib} ${STAGEDIR}${PREFIX}/lib/${lib}.0
	${LN} -sf ${PREFIX}/lib/${lib}.0 ${STAGEDIR}${PREFIX}/lib/${lib}
.endfor
.for lib in ${STALIBS:C|^|lib|:C|$|.a|}
	${INSTALL_LIB} ${RESDIR}/${lib} ${STAGEDIR}${PREFIX}/lib/
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
.for dir in ${SHRDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
