# New ports collection makefile for:	ja-xpdf
# Date created:		21 Avr 2002
# Whom:			MITA Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
DISTNAME=	xpdf-japanese

MAINTAINER=	mita@FreeBSD.org

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf\
		${LOCALBASE}/share/ghostscript/Resource/CMap/Adobe-Japan1-0:${PORTSDIR}/print/adobe-cmaps\
		${PKG_DBDIR}/ja-alias-fonts-1.0:${PORTSDIR}/japanese/alias-fonts

NO_BUILD=	yes
USE_X_PREFIX=	yes
INSTALL_FILES=	Adobe-Japan1.cidToUnicode ISO-2022-JP.unicodeMap \
		EUC-JP.unicodeMap Shift-JIS.unicodeMap \
		README
do-install:
	${MKDIR} ${PREFIX}/share/xpdf/japanese
.for i in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/xpdf/japanese
.endfor
	${INSTALL_DATA} ${FILESDIR}/dot.xpdfrc ${PREFIX}/share/xpdf/japanese
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
