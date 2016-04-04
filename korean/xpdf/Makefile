# Created by: Jung-uk Kim <jkim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpdf
PORTVERSION=	3.03
PORTREVISION=	3
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
PKGNAMESUFFIX=	-kofont
DISTNAME=	xpdf-korean
DIST_SUBDIR=	${DISTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Korean font support for xpdf

RUN_DEPENDS=	xpdf:graphics/xpdf \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:print/adobe-cmaps \
		${FONTSDIR}/UnBatang.ttf:korean/unfonts-core

NO_BUILD=	yes
SUB_FILES=	dot.xpdfrc
SUB_LIST=	ADOBECMAPDIR=${ADOBECMAPDIR} \
		FONTSDIR=${FONTSDIR}
PLIST_SUB=	EXTRARC=${EXTRARC}

FONTSDIR=	${LOCALBASE}/share/fonts/unfonts-core
EXTRARC=	${DATADIR}/korean/dot.xpdfrc
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps
INSTALL_FILES=	Adobe-Korea1.cidToUnicode ISO-2022-KR.unicodeMap \
		README ../dot.xpdfrc

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/korean
	cd ${WRKSRC} && \
	    ${INSTALL_DATA} ${INSTALL_FILES} ${STAGEDIR}${DATADIR}/korean
	${MKDIR} ${STAGEDIR}${DATADIR}/korean/CMap
	cd ${STAGEDIR}${DATADIR}/korean/CMap && \
	    ${FIND} ${ADOBECMAPDIR}/ak12/CMap \
		-type f -exec ${LN} -s -f {} . \;

.include <bsd.port.mk>
