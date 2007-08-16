# New ports collection makefile for:	Muggy
# Date created:		25 March 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	muggy
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	editors windowmaker tkstep80
MASTER_SITES=	http://www.aaa-int.or.jp/~jfactory/JDE/dist/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kiri
DISTNAME=	Muggy-${PORTVERSION}
EXTRACT_ONLY=	# extracted directly in install target

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple text editor for the X on TkStep

RUN_DEPENDS=	${LOCALBASE}/lib/tkstep8.0/tkstep.tcl:${PORTSDIR}/x11-toolkits/tkstep80
LIB_DEPENDS=	img.1:${PORTSDIR}/graphics/libimg-tkstep80

DEPRECATED=	development stalled for years, unmaintained
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
	${INSTALL_DATA} ${PREFIX}/JDE/Muggy/docs/Muggy.logo.xpm ${PIXMAPPATH}/Muggy.xpm

.include <bsd.port.mk>
