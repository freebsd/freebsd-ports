# New ports collection makefile for:	JDE's DeepForest
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	deepforest
PORTVERSION=	1.0a
CATEGORIES=	${CATEGORY_LIST}
MASTER_SITES=	${MASTER_SITE_LOCAL}
# http://www.aaa-int.or.jp/~jfactory/JDE/dist/
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	DeepForest-${PORTVERSION}
EXTRACT_ONLY=	# extracted directly in install target

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

RUN_DEPENDS=	${RUN_DEP_LIST}
LIB_DEPENDS=	${LIB_DEP_LIST}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes
SCRIPTS_ENV=	LANG=C LN=${LN} PERL=${PERL} LANGUAGE=${LANGUAGE} VERSION=${TKSTEPVERSION}
PLIST_SUB=	PIXMAP_PATH=${PIXMAPPATH:S@^${PREFIX}/@@}

# This port is for both archivers/deepforest and japanese/deepforest.
# But archivers/deepforest and japanese/deepforest are mutually exclusive and
# SHOULD NOT BE INSTALLED SIMULTANEOUSLY!
TKSTEPVERSION=	8.0
PIXMAPPATH?=	${PREFIX}/share/WindowMaker/Pixmaps
LANGUAGE?=
.if (${LANGUAGE} == "Japanese")
CATEGORY_LIST=	japanese windowmaker tkstep80 japanese
RUN_DEP_LIST=	${LOCALBASE}/lib/tkstep8.0jp/tkstep.tcl:${PORTSDIR}/japanese/tkstep80 \
		${LOCALBASE}/lib/Img1.2/libimg12.so.1:${PORTSDIR}/japanese/libimg
.else
CATEGORY_LIST=	archivers windowmaker tkstep80
RUN_DEP_LIST=	${LOCALBASE}/lib/tkstep8.0/tkstep.tcl:${PORTSDIR}/x11-toolkits/tkstep80
LIB_DEP_LIST=	img.1:${PORTSDIR}/graphics/libimg
.endif

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}
	${MKDIR} ${PIXMAPPATH}
	${INSTALL_DATA} ${PREFIX}/JDE/DeepForest/docs/DeepForest.xpm ${PIXMAPPATH}

.include <bsd.port.mk>
