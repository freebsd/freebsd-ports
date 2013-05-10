# Created by: chshen <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	3.03
PORTEPOCH=	2
CATEGORIES=	chinese graphics print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_TEX_CTAN} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	support/xpdf
PKGNAMESUFFIX=	-zhfont
DISTFILES=	xpdf-chinese-simplified-2011-sep-02${EXTRACT_SUFX} \
		xpdf-chinese-traditional-2011-sep-02${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}-chinese-${PORTVERSION}

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
	${MKDIR} ${DATADIR}/chinese-traditional/CMap
	cd ${DATADIR}/chinese-traditional/CMap && \
		${FIND} ${ADOBECMAPDIR}/ac15/CMap \
			-type f -exec ${LN} -s -f {} . \;
	${MKDIR} ${DATADIR}/chinese-simplified/CMap
	cd ${DATADIR}/chinese-simplified/CMap && \
		${FIND} ${ADOBECMAPDIR}/ag15/CMap \
			-type f -exec ${LN} -s -f {} . \;

post-install:
	exec < ${LOCALBASE}/etc/xpdfrc; \
		${RM} -f ${LOCALBASE}/etc/xpdfrc; \
		( ${GREP} -v "${EXTRARC}"; \
		${ECHO_CMD} "include ${EXTRARC}" ) \
		> ${LOCALBASE}/etc/xpdfrc
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${LOCALBASE}/etc/xpdfrc
	${CHMOD} 0444 ${LOCALBASE}/etc/xpdfrc

.include <bsd.port.mk>
