# $FreeBSD$

PORTNAME=	nanumfonts
PORTVERSION=	20170921
CATEGORIES=	korean
MASTER_SITES=	http://appdown.naver.com/naver/font/NanumFont/setup/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-${FONTTYPE}
DISTFILES=	${DISTFILE_LIST:S/^/${DISTFILE_PRFX}/:S/$/${DISTFILE_SUFX}/}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Nanum family Hangul fonts (${FONTFORMAT})

LICENSE=	OFL11

DISTFILE_LIST=	ALL
DISTFILE_PRFX=	NanumFontSetup_${FONTTYPE:tu}_
DISTFILE_SUFX=	_hangeulcamp.exe
DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTTYPE}

EXTRACT_AFTER_ARGS=	${EXTRACT_SUBDIR}
EXTRACT_SUBDIR=	\$$WINDIR/Fonts

NO_ARCH=	yes
NO_BUILD=	yes
USES=		7z:p7zip fonts

FONTTYPE?=	otf
FONTFORMAT?=	OpenType

FONTNAME=	nanum-${FONTTYPE}
FONTLIST=	BarunGothic \
		BarunGothicBold \
		BarunGothicLight \
		BarunGothicUltraLight \
		BarunpenB \
		BarunpenR \
		Brush \
		Gothic \
		GothicBold \
		GothicExtraBold \
		GothicLight \
		Myeongjo \
		MyeongjoBold \
		MyeongjoExtraBold \
		Pen \
		SquareB \
		SquareEB \
		SquareL \
		SquareR
.if ${FONTTYPE} == otf
FONTLIST+=	SquareRoundOTFB \
		SquareRoundOTFEB \
		SquareRoundOTFL \
		SquareRoundOTFR
.else
FONTLIST+=	SquareRoundB \
		SquareRoundEB \
		SquareRoundL \
		SquareRoundR
.endif
FONTFILES=	${FONTLIST:S|^|Nanum|:S|$|.${FONTTYPE}|}

PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

OPTIONS_DEFINE=	ECO

ECO_DESC=	Include Eco family fonts
ECO_VARS=	DISTFILE_LIST+="GOTHICECO MYUNGJOECO"
.for f in GothicEco MyeongjoEco
ECO_VARS+=	FONTLIST+="${f} ${f}Bold ${f}ExtraBold"
.endfor

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for f in ${FONTFILES}
	${INSTALL_DATA} ${WRKDIR}/${EXTRACT_SUBDIR}/${f} ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.post.mk>
