# New ports collection makefile for:	zh-xpdf
# Date created:		21 Avr 2002
# Whom:			chshen <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	20040727
CATEGORIES=	chinese graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/xpdf
DISTFILES=	xpdf-chinese-simplified-2004-jul-27.tar.gz \
		xpdf-chinese-traditional-2004-jul-27.tar.gz

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Chinese xpdf font support

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf\
		${LOCALBASE}/share/ghostscript/Resource/CMap/Adobe-CNS1-0:${PORTSDIR}/print/adobe-cmaps \
		${LOCALBASE}/share/fonts/TrueType/arphic/logo.gif:${PORTSDIR}/chinese/arphicttf

NO_BUILD=	yes
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
SIMP_FILES=	Adobe-GB1.cidToUnicode EUC-CN.unicodeMap GBK.unicodeMap \
		ISO-2022-CN.unicodeMap README
TRAD_FILES=	Adobe-CNS1.cidToUnicode Big5.unicodeMap \
		Big5ascii.unicodeMap README
do-install:
	${MKDIR} ${PREFIX}/share/xpdf/chinese-simplified
.for i in ${SIMP_FILES}
	${INSTALL_DATA} ${WRKSRC}/xpdf-chinese-simplified/${i} ${PREFIX}/share/xpdf/chinese-simplified
.endfor
	${MKDIR} ${PREFIX}/share/xpdf/chinese-traditional
.for i in ${TRAD_FILES}
	${INSTALL_DATA} ${WRKSRC}/xpdf-chinese-traditional/${i} ${PREFIX}/share/xpdf/chinese-traditional
.endfor
	${INSTALL_DATA} ${FILESDIR}/dot.xpdfrc ${PREFIX}/share/xpdf/chinese-traditional
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
