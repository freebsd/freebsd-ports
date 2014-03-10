# $FreeBSD$

PORTNAME=	nanumcoding
PORTVERSION=	2.0
CATEGORIES=	korean
MASTER_SITES=	http://dev.naver.com/frs/download.php/441/ \
		LOCAL
MASTER_SITE_SUBDIR=	jkim
PKGNAMESUFFIX=	-ttf
DISTNAME=	NanumGothicCoding-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	NanumGothic Coding Hangul font (TrueType)

LICENSE=	OFL11

BUILD_DEPENDS=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_WRKSUBDIR=	yes
USES=		zip
FONTSDIR=	lib/X11/fonts/nanum-coding${PKGNAMESUFFIX}
FONTLIST=	NanumGothicCoding \
		NanumGothicCoding-Bold
FONTFILES=	${FONTLIST:S/$/.ttf/} fonts.dir fonts.scale

PLIST_DIRS=	${FONTSDIR}
PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|}

post-extract:
	@# XXX File names are encoded in EUC-KR.
	${MV} ${WRKSRC}/*-Bold.ttf ${WRKSRC}/NanumGothicCoding-Bold.tmp
	${MV} ${WRKSRC}/*.ttf ${WRKSRC}/NanumGothicCoding.ttf
	${MV} ${WRKSRC}/*-Bold.tmp ${WRKSRC}/NanumGothicCoding-Bold.ttf

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
