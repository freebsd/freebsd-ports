# New ports collection makefile for:	ko-xpdf
# Date created:		Fri Sep 30 21:26:35 EDT 2005
# Whom:			Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	3.01
PORTREVISION=	1
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
DISTNAME=	xpdf-korean

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Korean xpdf font support

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		${X11BASE}/lib/X11/fonts/TrueType/UnBatang.ttf:${PORTSDIR}/korean/unfonts-ttf

NO_BUILD=	yes
USE_X_PREFIX=	yes
SUB_FILES=	dot.xpdfrc
SUB_LIST=	ADOBECMAPDIR=${ADOBECMAPDIR}

ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps
INSTALL_FILES=	Adobe-Korea1.cidToUnicode ISO-2022-KR.unicodeMap \
		README

.if defined(WITHOUT_X11)
BROKEN=		Broken dependency when WITHOUT_X11 set
.endif

do-install:
	${MKDIR} ${DATADIR}/korean
	${INSTALL_DATA} ${WRKDIR}/dot.xpdfrc ${DATADIR}/korean
.for i in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DATADIR}/korean
.endfor
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
