PORTNAME=	d2coding
PORTVERSION=	1.3.2
CATEGORIES=	korean x11-fonts
MASTER_SITES=	https://github.com/naver/d2codingfont/releases/download/VER${PORTVERSION}/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-ttf
DISTNAME=	D2Coding-Ver${PORTVERSION}-${PORTRELEASE}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	D2Coding Hangul font

LICENSE=	OFL11

NO_ARCH=	yes
NO_BUILD=	yes
USES=		fonts zip

FONTLIST=	D2Coding D2CodingLigature
FONTFILES=	${FONTLIST:S|$|.ttf|} ${FONTLIST:S|$|Bold.ttf|}
PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

PORTRELEASE=	20180524

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/D2Coding/${DISTNAME}.ttf \
	    ${STAGEDIR}${FONTSDIR}/D2Coding.ttf
	${INSTALL_DATA} ${WRKDIR}/D2Coding/${DISTNAME:S|^D2Coding|D2CodingBold|}.ttf \
	    ${STAGEDIR}${FONTSDIR}/D2CodingBold.ttf
	${INSTALL_DATA} ${WRKDIR}/D2CodingLigature/${DISTNAME}-ligature.ttf \
	    ${STAGEDIR}${FONTSDIR}/D2CodingLigature.ttf
	${INSTALL_DATA} ${WRKDIR}/D2CodingLigature/${DISTNAME:S|^D2Coding|D2CodingBold|}-ligature.ttf \
	    ${STAGEDIR}${FONTSDIR}/D2CodingLigatureBold.ttf

.include <bsd.port.mk>
