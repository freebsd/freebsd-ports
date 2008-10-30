# New ports collection makefile for:	ko-xpdf
# Date created:		Fri Sep 30 21:26:35 EDT 2005
# Whom:			Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xpdf
PORTVERSION=	3.02
PORTREVISION=	1
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
PKGNAMESUFFIX=	-kofont
DISTNAME=	xpdf-korean

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Korean font support for xpdf

RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf \
		${ADOBECMAPDIR}/ai0/CMap/Identity-H:${PORTSDIR}/print/adobe-cmaps \
		${FONTSDIR}/UnBatang.ttf:${PORTSDIR}/korean/unfonts-ttf

NO_BUILD=	yes
SUB_FILES=	dot.xpdfrc
SUB_LIST=	ADOBECMAPDIR=${ADOBECMAPDIR} \
		FONTSDIR=${FONTSDIR}
PLIST_SUB=	EXTRARC=${EXTRARC}
DATADIR=	${PREFIX}/share/xpdf

FONTSDIR=	${LOCALBASE}/lib/X11/fonts/TrueType
EXTRARC=	${DATADIR}/korean/dot.xpdfrc
ADOBECMAPDIR=	${LOCALBASE}/share/fonts/adobe-cmaps
INSTALL_FILES=	Adobe-Korea1.cidToUnicode ISO-2022-KR.unicodeMap \
		README ../dot.xpdfrc

do-install:
	${MKDIR} ${DATADIR}/korean
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${INSTALL_FILES} ${DATADIR}/korean

post-install:
	exec < ${LOCALBASE}/etc/xpdfrc; \
		${RM} -f ${LOCALBASE}/etc/xpdfrc; \
		( ${GREP} -v "${EXTRARC}"; \
		  ${ECHO_CMD} "include ${EXTRARC}" ) \
		> ${LOCALBASE}/etc/xpdfrc
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${LOCALBASE}/etc/xpdfrc
	${CHMOD} 0444 ${LOCALBASE}/etc/xpdfrc

.include <bsd.port.mk>
