# New ports collection makefile for:	zh-xpdf
# Date created:		21 Avr 2002
# Whom:			chshen <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	1.01
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
DISTNAME=	xpdf-chinese-traditional

MAINTAINER=	statue@freebsd.sinica.edu.tw

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf\
		${LOCALBASE}/share/ghostscript/Resource/CMap/Adobe-CNS1-0:${PORTSDIR}/print/adobe-cmaps

NO_BUILD=	yes
USE_X_PREFIX=	yes
INSTALL_FILES=	Adobe-CNS1.cidToUnicode Big5.unicodeMap \
		Big5ascii.unicodeMap README
do-install:
	${MKDIR} ${PREFIX}/share/xpdf/chinese-traditional
.for i in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/xpdf/chinese-traditional
.endfor
	${INSTALL_DATA} ${FILESDIR}/dot.xpdfrc ${PREFIX}/share/xpdf/chinese-traditional
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
