PORTNAME=	nanum
DISTVERSION=	2.5
CATEGORIES=	korean x11-fonts
MASTER_SITES=	https://github.com/naver/nanumfont/releases/download/VER${DISTVERSION}/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-gothic-coding
DISTNAME=	NanumGothicCoding-${DISTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	NanumGothicCoding Hangul font (TrueType)

LICENSE=	OFL11
LICENSE_FILE=	${FILESDIR}/LICENSE

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		fonts zip
FONTLIST=	NanumGothicCoding \
		NanumGothicCoding-Bold
FONTFILES=	${FONTLIST:S/$/.ttf/}

PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FONTFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
