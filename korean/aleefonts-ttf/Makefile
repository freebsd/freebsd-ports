# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	aleefonts
PORTVERSION=	12
CATEGORIES=	korean x11-fonts
MASTER_SITES=	DEBIAN
MASTER_SITE_SUBDIR=	pool/main/t/ttf-alee
PKGNAMESUFFIX=	-ttf
DISTNAME=	ttf-alee_${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	A-Lee's Hangul truetype fonts #'

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS+=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTSDIR=	lib/X11/fonts/alee${PKGNAMESUFFIX}
FONTLIST=	Bandal Bangwool Eunjin EunjinNakseo Guseul

PLIST_DIRS=	${FONTSDIR}
.for f in ${FONTLIST}
PLIST_FILES+=	${FONTSDIR}/${f}.ttf
.endfor
PLIST_FILES+=	${FONTSDIR}/fonts.dir \
		${FONTSDIR}/fonts.scale

NO_STAGE=	yes
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
