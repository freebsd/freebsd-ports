# $FreeBSD$

PORTNAME=	nanumfonts
PORTVERSION=	20141022
CATEGORIES=	korean
MASTER_SITES=	http://appdown.naver.com/naver/font/NanumFont/setup/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-${FONTTYPE}
DISTFILES=	${DISTFILE_LIST:S/^/${DISTFILE_PRFX}/:S/$/${DISTFILE_SUFX}/}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Nanum family Hangul fonts (${FONTFORMAT})

LICENSE=	OFL11

EXTRACT_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

DISTFILE_LIST=	ALL GOTHICECO MYUNGJOECO
DISTFILE_PRFX=	NanumFontSetup_${FONTTYPE:tu}_
DISTFILE_SUFX=	_hangeulcamp.exe
DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTTYPE}

EXTRACT_CMD=	7z
EXTRACT_BEFORE_ARGS=	e -y
EXTRACT_AFTER_ARGS=	'$$WINDIR/Fonts'

NO_ARCH=	yes
NO_BUILD=	yes
USES=		fonts

FONTTYPE?=	otf
FONTFORMAT?=	OpenType

FONTNAME=	nanum-${FONTTYPE}
FONTLIST=	NanumBarunGothic \
		NanumBarunGothicBold \
		NanumBarunGothicLight \
		NanumBarunGothicUltraLight \
		NanumBarunpenB \
		NanumBarunpenR \
		NanumBrush \
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
FONTFILES=	${FONTLIST:S|$|.${FONTTYPE}|}

PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for f in ${FONTFILES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
