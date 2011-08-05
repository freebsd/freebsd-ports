# New ports collection makefile for:	Nanum Gothic Coding Hangul font
# Date created:		August 4, 2011
# Whom:			Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nanumcoding
PORTVERSION=	2.0
CATEGORIES=	korean
MASTER_SITES=	http://dev.naver.com/frs/download.php/441/
PKGNAMESUFFIX=	-ttf
DISTNAME=	NanumGothicCoding-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Nanum Gothic Coding Hangul font (TrueType)

LICENSE=	OFL
LICENSE_NAME=	Open Font License version 1.1
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS+=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
FONTSDIR=	lib/X11/fonts/nanum-coding-ttf
PLIST_SUB+=	FONTSDIR=${FONTSDIR}

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
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.scale ${PREFIX}/${FONTSDIR}

post-install:
	@-${LOCALBASE}/bin/fc-cache -s ${PREFIX}/${FONTSDIR} 2>/dev/null

.include <bsd.port.mk>
