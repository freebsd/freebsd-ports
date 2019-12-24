# Created by: MITA Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	4.02
CATEGORIES=	japanese
MASTER_SITES=	https://xpdfreader-dl.s3.amazonaws.com/
PKGNAMESUFFIX=	-jafont
DISTNAME=	xpdf-japanese
DIST_SUBDIR=	${DISTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese font support for xpdf

LICENSE=	GPLv2

RUN_DEPENDS=	xpdf:graphics/xpdf \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:print/adobe-cmaps \
		${FONTSDIR}/Ryumin-Light:japanese/font-std \
		${FONTSDIR}/GothicBBB-Medium:japanese/font-std

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

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/japanese
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${INSTALL_FILES} ${STAGEDIR}${DATADIR}/japanese
	${MKDIR} ${STAGEDIR}${DATADIR}/japanese/CMap
	cd ${STAGEDIR}${DATADIR}/japanese/CMap && \
	    ${FIND} ${ADOBECMAPDIR}/aj16/CMap ${ADOBECMAPDIR}/aj20/CMap \
		-type f -exec ${LN} -s -f {} . \;

.include <bsd.port.mk>
