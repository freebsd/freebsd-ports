# New ports collection makefile for:	Muggy
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	muggy
PORTVERSION=	1.3.1
CATEGORIES+=	editors windowmaker tkstep80

MASTER_SITES=	http://www.aaa-int.or.jp/~jfactory/Factory/JDE/dist/
DISTNAME=	Muggy-${PORTVERSION}

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

RUN_DEPENDS=	${RUN_DEP_LIST}
LIB_DEPENDS=	${LIB_DEP_LIST}

EXTRACT_ONLY=	# extracted directly in install target
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes
SCRIPTS_ENV=	LANG=C LN=${LN} PERL=${PERL} LANGUAGE=${LANGUAGE} VERSION=${TKSTEPVERSION}
PLIST_SUB=	PIXMAP_PATH=${PIXMAPPATH:S@^${PREFIX}/@@}

# This port is for both editors/muggy and japanese/muggy.
# But editors/muggy and japanese/muggy are mutually exclusive and
# SHOULD NOT BE INSTALLED SIMULTANEOUSLY!
TKSTEPVERSION=	8.0
PIXMAPPATH?=	${PREFIX}/share/WindowMaker/Pixmaps
LANGUAGE?=
.if (${LANGUAGE} == "Japanese")
RUN_DEP_LIST=	${LOCALBASE}/lib/Img1.2/libimg12.so.1:${PORTSDIR}/japanese/libimg \
		${LOCALBASE}/lib/tkstep8.0jp/tkstep.tcl:${PORTSDIR}/japanese/tkstep80
.else
RUN_DEP_LIST=	${LOCALBASE}/lib/tkstep8.0/tkstep.tcl:${PORTSDIR}/x11-toolkits/tkstep80
LIB_DEP_LIST=	img.1:${PORTSDIR}/graphics/libimg
.endif

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}
	${MKDIR} ${PIXMAPPATH}
	${INSTALL_DATA} ${PREFIX}/JDE/Muggy/docs/Muggy.logo.xpm ${PIXMAPPATH}/Muggy.xpm

.include <bsd.port.mk>
