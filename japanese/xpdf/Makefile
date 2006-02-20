# New ports collection makefile for:	ja-xpdf
# Date created:		21 Avr 2002
# Whom:			MITA Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	3.00
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
DISTNAME=	xpdf-japanese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese xpdf font support

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		${X11BASE}/lib/X11/fonts/TrueType/kochi-mincho-subst.ttf:${PORTSDIR}/japanese/kochi-ttfonts

USE_X_PREFIX=	yes
NO_BUILD=	yes
SUB_FILES=	dot.xpdfrc
SUB_LIST=	ADOBECMAPDIR=${ADOBECMAPDIR}

INSTALL_FILES=	Adobe-Japan1.cidToUnicode ISO-2022-JP.unicodeMap \
		EUC-JP.unicodeMap Shift-JIS.unicodeMap \
		README
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps

.if defined(WITHOUT_X11)
BROKEN=		"Broken dependency when WITHOUT_X11 set"
.endif

do-install:
	${MKDIR} ${PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKDIR}/dot.xpdfrc ${PREFIX}/share/xpdf/japanese
.for i in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/xpdf/japanese
.endfor
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
