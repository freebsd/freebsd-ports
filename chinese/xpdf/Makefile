# New ports collection makefile for:	zh-xpdf
# Date created:		21 Avr 2002
# Whom:			chshen <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	3.02
PORTEPOCH=	2
CATEGORIES=	chinese graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	support/xpdf
PKGNAMESUFFIX=	-zhfont
DISTFILES=	xpdf-chinese-simplified-2004-jul-27.tar.gz \
		xpdf-chinese-traditional-2004-jul-27.tar.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Chinese font support for xpdf

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		${FONTSDIR}/STHeiti-Regular:${PORTSDIR}/chinese/font-std \
		${FONTSDIR}/STSong-Light:${PORTSDIR}/chinese/font-std \
		${FONTSDIR}/MSung-Light:${PORTSDIR}/chinese/font-std

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	dot.xpdfrc
SUB_LIST=	ADOBECMAPDIR=${ADOBECMAPDIR} \
		FONTSDIR=${FONTSDIR}
PLIST_SUB=	EXTRARC=${EXTRARC}
DATADIR=	${PREFIX}/share/xpdf

FONTSDIR=	${LOCALBASE}/share/fonts/std.zh_CN
EXTRARC=	${DATADIR}/chinese-traditional/dot.xpdfrc
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps
SIMP_FILES=	Adobe-GB1.cidToUnicode EUC-CN.unicodeMap GBK.unicodeMap \
		ISO-2022-CN.unicodeMap README
TRAD_FILES=	Adobe-CNS1.cidToUnicode Big5.unicodeMap \
		Big5ascii.unicodeMap README

do-install:
	${MKDIR} ${DATADIR}/chinese-simplified
	cd ${WRKSRC}/xpdf-chinese-simplified \
		&& ${INSTALL_DATA} ${SIMP_FILES} ${DATADIR}/chinese-simplified
	${MKDIR} ${DATADIR}/chinese-traditional
	cd ${WRKSRC}/xpdf-chinese-traditional \
		&& ${INSTALL_DATA} ${TRAD_FILES} ${DATADIR}/chinese-traditional
	${INSTALL_DATA} ${WRKSRC}/dot.xpdfrc ${DATADIR}/chinese-traditional

post-install:
	exec < ${LOCALBASE}/etc/xpdfrc; \
		${RM} -f ${LOCALBASE}/etc/xpdfrc; \
		( ${GREP} -v "${EXTRARC}"; \
		${ECHO_CMD} "include ${EXTRARC}" ) \
		> ${LOCALBASE}/etc/xpdfrc
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${LOCALBASE}/etc/xpdfrc
	${CHMOD} 0444 ${LOCALBASE}/etc/xpdfrc

.include <bsd.port.mk>
