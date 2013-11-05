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

BUILD_DEPENDS+=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
FONTSDIR=	lib/X11/fonts/nanum-coding${PKGNAMESUFFIX}
FONTLIST=	NanumGothicCoding \
		NanumGothicCoding-Bold

PLIST_DIRS=	${FONTSDIR}
.for f in ${FONTLIST}
PLIST_FILES+=	${FONTSDIR}/${f}.ttf
.endfor
PLIST_FILES+=	${FONTSDIR}/fonts.dir \
		${FONTSDIR}/fonts.scale

NO_STAGE=	yes
post-extract:
	@# XXX File names are encoded in EUC-KR.
	${MV} ${WRKSRC}/*-Bold.ttf ${WRKSRC}/NanumGothicCoding-Bold.tmp
	${MV} ${WRKSRC}/*.ttf ${WRKSRC}/NanumGothicCoding.ttf
	${MV} ${WRKSRC}/*-Bold.tmp ${WRKSRC}/NanumGothicCoding-Bold.ttf

do-build:
	${LOCALBASE}/bin/mkfontscale ${WRKSRC}
	${LOCALBASE}/bin/mkfontdir ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
.for f in ${FONTLIST}
	${INSTALL_DATA} ${WRKSRC}/${f}.ttf ${PREFIX}/${FONTSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.scale ${PREFIX}/${FONTSDIR}

post-install:
	@${ECHO_CMD} "@exec fc-cache -s %D/${FONTSDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec fc-cache -s %D/${FONTSDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@-${LOCALBASE}/bin/fc-cache -s ${PREFIX}/${FONTSDIR} 2>/dev/null

.include <bsd.port.mk>
