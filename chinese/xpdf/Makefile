# Created by: chshen <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	3.03
PORTEPOCH=	2
CATEGORIES=	chinese graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		TEX_CTAN/support/xpdf \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	-zhfont
DISTFILES=	xpdf-chinese-simplified-2011-sep-02${EXTRACT_SUFX} \
		xpdf-chinese-traditional-2011-sep-02${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}-chinese-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Chinese font support for xpdf

RUN_DEPENDS=	xpdf:graphics/xpdf \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:print/adobe-cmaps \
		${FONTSDIR}/STHeiti-Regular:chinese/font-std \
		${FONTSDIR}/STSong-Light:chinese/font-std \
		${FONTSDIR}/MSung-Light:chinese/font-std

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	dot.xpdfrc
SUB_LIST=	ADOBECMAPDIR=${ADOBECMAPDIR} \
		FONTSDIR=${FONTSDIR}
PLIST_SUB=	EXTRARC=${EXTRARC}

FONTSDIR=	${LOCALBASE}/share/fonts/std.zh_CN
EXTRARC=	${DATADIR}/chinese-traditional/dot.xpdfrc
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps
SIMP_FILES=	Adobe-GB1.cidToUnicode EUC-CN.unicodeMap GBK.unicodeMap \
		ISO-2022-CN.unicodeMap README
TRAD_FILES=	Adobe-CNS1.cidToUnicode Big5.unicodeMap \
		Big5ascii.unicodeMap README

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/chinese-simplified
	cd ${WRKSRC}/xpdf-chinese-simplified && \
	    ${INSTALL_DATA} ${SIMP_FILES} \
		${STAGEDIR}${DATADIR}/chinese-simplified
	${MKDIR} ${STAGEDIR}${DATADIR}/chinese-traditional
	cd ${WRKSRC}/xpdf-chinese-traditional && \
	    ${INSTALL_DATA} ${TRAD_FILES} \
		${STAGEDIR}${DATADIR}/chinese-traditional
	${INSTALL_DATA} ${WRKDIR}/dot.xpdfrc \
	    ${STAGEDIR}${DATADIR}/chinese-traditional
	${MKDIR} ${STAGEDIR}${DATADIR}/chinese-traditional/CMap
	cd ${STAGEDIR}${DATADIR}/chinese-traditional/CMap && \
	    ${FIND} ${ADOBECMAPDIR}/ac15/CMap \
		-type f -exec ${LN} -s -f {} . \;
	${MKDIR} ${STAGEDIR}${DATADIR}/chinese-simplified/CMap
	cd ${STAGEDIR}${DATADIR}/chinese-simplified/CMap && \
	    ${FIND} ${ADOBECMAPDIR}/ag15/CMap \
		-type f -exec ${LN} -s -f {} . \;

.include <bsd.port.mk>
