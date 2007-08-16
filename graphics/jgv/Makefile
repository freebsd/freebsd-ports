# New ports collection makefile for:	JDE's JGV
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	jgv
PORTVERSION=	0.2a
PORTREVISION=	3
CATEGORIES=	graphics windowmaker tkstep80
MASTER_SITES=	http://www.aaa-int.or.jp/~jfactory/JDE/dist/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kiri
DISTNAME=	JGV-${PORTVERSION}
EXTRACT_ONLY=	# extracted directly in install target

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphic viewer with various image types

RUN_DEPENDS=	${LOCALBASE}/lib/tkstep8.0/tkstep.tcl:${PORTSDIR}/x11-toolkits/tkstep80
LIB_DEPENDS=	img.1:${PORTSDIR}/graphics/libimg-tkstep80

DEPRECATED=	development stalled for years, outdated, unmaintained
EXPIRATION_DATE=	2007-11-16

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
REINPLACE_ARGS=
TKSTEPVERSION=	8.0
PIXMAPPATH?=	${PREFIX}/share/WindowMaker/Pixmaps
SCRIPTS_ENV=	LANG=C LN=${LN} REINPLACE_CMD="${REINPLACE_CMD}" \
		LANGUAGE=${LANGUAGE} VERSION=${TKSTEPVERSION}
PLIST_SUB=	PIXMAP_PATH=${PIXMAPPATH:S@^${PREFIX}/@@}

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}
	${MKDIR} ${PIXMAPPATH}
	${INSTALL_DATA} ${PREFIX}/JDE/JGV/docs/JGV.xpm ${PIXMAPPATH}

.include <bsd.port.mk>
