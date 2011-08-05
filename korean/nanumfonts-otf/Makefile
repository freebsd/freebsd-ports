# New ports collection makefile for:	Nanum Hangul fonts
# Date created:		August 4, 2011
# Whom:			Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nanumfonts
PORTVERSION=	3.0
CATEGORIES=	korean
MASTER_SITES=	http://cdn.naver.com/naver/NanumFont/fontfiles/
PKGNAMESUFFIX=	-${FONTTYPE}
DISTNAME=	NanumFont_${FONTTYPE:U}_ALL

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Nanum family Hangul fonts (${FONTFORMAT})

LICENSE=	OFL
LICENSE_NAME=	Open Font License version 1.1
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS+=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTTYPE}

NO_WRKSUBDIR=	yes
USE_ZIP=	yes

FONTTYPE?=	otf
FONTFORMAT?=	OpenType

FONTSDIR=	lib/X11/fonts/nanum-${FONTTYPE}
FONTLIST=	NanumBrush \
		NanumGothic \
		NanumGothicBold \
		NanumGothicExtraBold \
		NanumMyeongjo \
		NanumMyeongjoBold \
		NanumMyeongjoExtraBold \
		NanumPen

.for f in ${FONTLIST}
PLIST_FILES+=	${FONTSDIR}/${f}.${FONTTYPE}
.endfor
PLIST_FILES+=	${FONTSDIR}/fonts.dir \
		${FONTSDIR}/fonts.scale

do-build:
	${PREFIX}/bin/mkfontscale ${WRKSRC}
	${PREFIX}/bin/mkfontdir ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}
.for f in ${FONTLIST}
	${INSTALL_DATA} ${WRKSRC}/${f}.${FONTTYPE} ${PREFIX}/${FONTSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.scale ${PREFIX}/${FONTSDIR}

post-install:
	@${ECHO_CMD} "@dirrm ${FONTSDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec fc-cache -s %D/${FONTSDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec fc-cache -s %D/${FONTSDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@-${PREFIX}/bin/fc-cache -s ${PREFIX}/${FONTSDIR} 2>/dev/null

.include <bsd.port.mk>
