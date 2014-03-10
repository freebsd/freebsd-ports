# $FreeBSD$

PORTNAME=	nanumfonts
PORTVERSION=	3.1
CATEGORIES=	korean
MASTER_SITES=	http://cdn.naver.com/naver/NanumFont/fontfiles/ \
		LOCAL
MASTER_SITE_SUBDIR=	jkim
PKGNAMESUFFIX=	-${FONTTYPE}
DISTFILES=	NanumFont_${FONTTYPE:U}_ALL${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:U}_GOTHICECO${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:U}_GOTHICLIGHT${EXTRACT_SUFX} \
		NanumFontSetup_${FONTTYPE:U}_MYUNGJOECO${EXTRACT_SUFX}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Nanum family Hangul fonts (${FONTFORMAT})

LICENSE=	OFL11

BUILD_DEPENDS=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTTYPE}

NO_WRKSUBDIR=	yes
USES=		zip

FONTTYPE?=	otf
FONTFORMAT?=	OpenType

FONTSDIR=	lib/X11/fonts/nanum-${FONTTYPE}
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
FONTFILES=	${FONTLIST:S/$/.${FONTTYPE}/} fonts.dir fonts.scale

PLIST_DIRS=	${FONTSDIR}
PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

do-build:
	${LOCALBASE}/bin/mkfontscale ${WRKSRC}
	${LOCALBASE}/bin/mkfontdir ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${FONTFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/${FONTSDIR}

post-install:
	@${ECHO_CMD} "@exec fc-cache -s %D/${FONTSDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec fc-cache -s %D/${FONTSDIR} 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
