# $FreeBSD$

PORTNAME=	nanumcoding
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	korean
MASTER_SITES=	http://dev.naver.com/frs/download.php/441/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-ttf
DISTNAME=	NanumGothicCoding-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	NanumGothic Coding Hangul font (TrueType)

LICENSE=	OFL11

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		fonts zip
FONTNAME=	nanum-coding${PKGNAMESUFFIX}
FONTLIST=	NanumGothicCoding \
		NanumGothicCoding-Bold
FONTFILES=	${FONTLIST:S/$/.ttf/}

PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

post-extract:
	@# XXX File names are encoded in EUC-KR.
	${MV} ${WRKSRC}/*-Bold.ttf ${WRKSRC}/NanumGothicCoding-Bold.tmp
	${MV} ${WRKSRC}/*.ttf ${WRKSRC}/NanumGothicCoding.ttf
	${MV} ${WRKSRC}/*-Bold.tmp ${WRKSRC}/NanumGothicCoding-Bold.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FONTFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
