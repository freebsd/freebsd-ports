# New ports collection makefile for:	ko-xpdf
# Date created:		Fri Sep 30 21:26:35 EDT 2005
# Whom:			Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	3.01
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
DISTNAME=	xpdf-korean

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Korean xpdf font support

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf \
		${LOCALBASE}/share/ghostscript/Resource/CMap/Adobe-Korea1-0:${PORTSDIR}/print/adobe-cmaps \
		${X11BASE}/lib/X11/fonts/TrueType/UnBatang.ttf:${PORTSDIR}/korean/unfonts-ttf

USE_X_PREFIX=	yes
INSTALL_FILES=	Adobe-Korea1.cidToUnicode ISO-2022-KR.unicodeMap \
		README dot.xpdfrc

do-build:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	        -e 's|%%X11BASE%%|${X11BASE}|g' \
	        -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			${FILESDIR}/dot.xpdfrc > ${WRKSRC}/dot.xpdfrc

do-install:
	${MKDIR} ${PREFIX}/share/xpdf/korean
.for i in ${INSTALL_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/xpdf/korean
.endfor
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
