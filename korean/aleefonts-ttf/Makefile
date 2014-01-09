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

BUILD_DEPENDS=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
FONTSDIR=	lib/X11/fonts/alee${PKGNAMESUFFIX}
FONTLIST=	Bandal Bangwool Eunjin EunjinNakseo Guseul
FONTFILES=	${FONTLIST:S/$/.ttf/} fonts.dir fonts.scale

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
