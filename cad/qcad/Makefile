# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qcad
PORTVERSION=	3.2.1.0
CATEGORIES=	cad
MASTER_SITES=	http://github.com/${PORTNAME}/${PORTNAME}/archive/${DISTNAME}.tar.gz?dummy=/	\
		https://github.com/${PORTNAME}/${PORTNAME}/archive/${DISTNAME}.tar.gz?dummy=/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		qmake:${PORTSDIR}/devel/qmake	\
		${LOCALBASE}/lib/libopenNURBS.a:${PORTSDIR}/graphics/opennurbs
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

FETCH_ARGS=	-Fpr
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_UNSAFE=yes

USES=		gmake
USE_LDCONFIG=	yes
USE_QT4=	qmake clucene codecs-cn codecs-jp codecs-kr codecs-tw corelib	\
		dbus designer gui help imageformats network opengl script	\
		scripttools sql svg xml xmlpatterns webkit

DESKTOP_ENTRIES="${PORTNAME:U}"	\
		"A free application for computer aided drafting in two dimensions"\
		"${DATADIR}/scripts/qcad_icon.png"	\
		"${PREFIX}/bin/qcad-bin"	\
		"Engineering;"	\
		""

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

do-configure:
	cd ${WRKSRC} && ${QMAKE} -r

do-install:
	${INSTALL_PROGRAM} ${RESDIR}/qcad-bin ${PREFIX}/bin/
	${LN} -sf ${PREFIX}/bin/qcad-bin ${PREFIX}/bin/qcad
.for prog in ${QSCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/${prog} ${PREFIX}/bin
.endfor
.for lib in ${SHRLIBS:C|^|lib|:C|$|.so|}
	${INSTALL_LIB} ${RESDIR}/${lib} ${PREFIX}/lib/${lib}.0
	${LN} -sf ${PREFIX}/lib/${lib}.0 ${PREFIX}/lib/${lib}
.endfor
.for lib in ${STALIBS:C|^|lib|:C|$|.a|}
	${INSTALL_LIB} ${RESDIR}/${lib} ${PREFIX}/lib/
.endfor
	${MKDIR} ${DATADIR}
.for dir in ${SHRDIR}
	${CP} -Rp ${WRKSRC}/${dir} ${DATADIR}/
.endfor
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
