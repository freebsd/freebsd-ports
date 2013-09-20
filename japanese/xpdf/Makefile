# Created by: MITA Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	3.03
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
PKGNAMESUFFIX=	-jafont
DISTNAME=	xpdf-japanese
DIST_SUBDIR=	${DISTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese font support for xpdf

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		${FONTSDIR}/Ryumin-Light:${PORTSDIR}/japanese/font-std \
		${FONTSDIR}/GothicBBB-Medium:${PORTSDIR}/japanese/font-std

NO_BUILD=	yes
SUB_FILES=	dot.xpdfrc
SUB_LIST=	ADOBECMAPDIR=${ADOBECMAPDIR} \
		FONTSDIR=${FONTSDIR}
PLIST_SUB=	EXTRARC=${EXTRARC}

FONTSDIR=	${LOCALBASE}/share/fonts/std.ja_JP
EXTRARC=	${DATADIR}/japanese/dot.xpdfrc
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps
INSTALL_FILES=	Adobe-Japan1.cidToUnicode ISO-2022-JP.unicodeMap \
		EUC-JP.unicodeMap Shift-JIS.unicodeMap \
		README ../dot.xpdfrc

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/japanese
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${INSTALL_FILES} ${DATADIR}/japanese
	${MKDIR} ${DATADIR}/japanese/CMap
	cd ${DATADIR}/japanese/CMap && \
		${FIND} ${ADOBECMAPDIR}/aj16/CMap ${ADOBECMAPDIR}/aj20/CMap \
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
