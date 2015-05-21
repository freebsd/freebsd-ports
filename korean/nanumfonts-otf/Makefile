# $FreeBSD$

PORTNAME=	nanumfonts
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	korean
MASTER_SITES=	http://cdn.naver.com/naver/NanumFont/fontfiles/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-${FONTTYPE}
DISTFILES=	NanumFont_${FONTTYPE:tu}_ALL${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:tu}_GOTHICECO${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:tu}_GOTHICLIGHT${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:tu}_MYUNGJOECO${EXTRACT_SUFX}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Nanum family Hangul fonts (${FONTFORMAT})

LICENSE=	OFL11

DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTTYPE}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		fonts zip

FONTTYPE?=	otf
FONTFORMAT?=	OpenType

FONTNAME=	nanum-${FONTTYPE}
FONTLIST=	NanumBrush \
		NanumGothic \
		NanumGothicBold \
		NanumGothicEco \
		NanumGothicEcoBold \
		NanumGothicEcoExtraBold \
		NanumGothicExtraBold \
		NanumGothicLight \
		NanumMyeongjo \
		NanumMyeongjoBold \
		NanumMyeongjoEco \
		NanumMyeongjoEcoBold \
		NanumMyeongjoEcoExtraBold \
		NanumMyeongjoExtraBold \
		NanumPen
FONTFILES=	${FONTLIST:S/$/.${FONTTYPE}/}

PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FONTFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
