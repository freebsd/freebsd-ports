# New ports collection makefile for:	ja-xpdf
# Date created:		21 Avr 2002
# Whom:			MITA Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	3.00
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
DISTNAME=	xpdf-japanese

MAINTAINER=	mita@FreeBSD.org
COMMENT=	Japanese xpdf font support

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf \
		${LOCALBASE}/share/ghostscript/Resource/CMap/Adobe-Japan1-0:${PORTSDIR}/print/adobe-cmaps \
		${X11BASE}/lib/X11/fonts/TrueType/kochi-mincho-subst.ttf:${PORTSDIR}/japanese/kochi-ttfonts

USE_X_PREFIX=	yes
INSTALL_FILES=	Adobe-Japan1.cidToUnicode ISO-2022-JP.unicodeMap \
		EUC-JP.unicodeMap Shift-JIS.unicodeMap \
		README dot.xpdfrc

do-build:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	        -e 's|%%X11BASE%%|${X11BASE}|g' \
	        -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${FILESDIR}/dot.xpdfrc > ${WRKSRC}/dot.xpdfrc

do-install:
	${MKDIR} ${PREFIX}/share/xpdf/japanese
.for i in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/xpdf/japanese
.endfor
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
