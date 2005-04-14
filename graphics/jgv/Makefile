# New ports collection makefile for:	JDE's JGV
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	jgv
PORTVERSION=	0.2a
CATEGORIES+=	${CATEGORY_LIST}
MASTER_SITES=	http://www.aaa-int.or.jp/~jfactory/JDE/dist/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	. kiri
DISTNAME=	JGV-${PORTVERSION}
EXTRACT_ONLY=	# extracted directly in install target

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphic viewer with various image types

RUN_DEPENDS=	${RUN_DEP_LIST}
LIB_DEPENDS=	${LIB_DEP_LIST}

CONFLICTS?=	ja-jgv-[0-9]*

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=
SCRIPTS_ENV=	LANG=C LN=${LN} REINPLACE_CMD="${REINPLACE_CMD}" \
		LANGUAGE=${LANGUAGE} VERSION=${TKSTEPVERSION}
PLIST_SUB=	PIXMAP_PATH=${PIXMAPPATH:S@^${PREFIX}/@@}

TKSTEPVERSION=	8.0
PIXMAPPATH?=	${PREFIX}/share/WindowMaker/Pixmaps
LANGUAGE?=
.if (${LANGUAGE} == "Japanese")
CATEGORY_LIST=	graphics windowmaker tkstep80 japanese
RUN_DEP_LIST=	${LOCALBASE}/lib/Img1.2/libimg12.so.1:${PORTSDIR}/japanese/libimg \
		${LOCALBASE}/lib/tkstep8.0jp/tkstep.tcl:${PORTSDIR}/japanese/tkstep80
.else
CATEGORY_LIST=	graphics windowmaker tkstep80
LIB_DEP_LIST=	img.1:${PORTSDIR}/graphics/libimg
RUN_DEP_LIST=	${LOCALBASE}/lib/tkstep8.0/tkstep.tcl:${PORTSDIR}/x11-toolkits/tkstep80
.endif

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}
	${MKDIR} ${PIXMAPPATH}
	${INSTALL_DATA} ${PREFIX}/JDE/JGV/docs/JGV.xpm ${PIXMAPPATH}

.include <bsd.port.mk>
