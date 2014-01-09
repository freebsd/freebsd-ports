# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unfonts
PORTVERSION?=	1.0.2.080608
CATEGORIES=	korean x11-fonts
MASTER_SITES?=	http://kldp.net/frs/download.php/4695/
PKGNAMESUFFIX=	-${FONTCAT}
DISTNAME=	un-fonts${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	GPL'd Korean TrueType Fonts by UN Koaunghi (${FONTCAT})

LICENSE=	GPLv2
LICENSE_FILE=	${FILESDIR}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

DISTINFO_FILE=	${PKGDIR}/distinfo.${FONTCAT}-ttf

WRKSRC=		${WRKDIR}/un-fonts
FONTSDIR=	lib/X11/fonts/${PORTNAME}-${FONTCAT}
FONTCAT?=	core
FONTLIST?=	UnBatang \
		UnBatangBold \
		UnDinaru \
		UnDinaruBold \
		UnDinaruLight \
		UnDotum \
		UnDotumBold \
		UnGraphic \
		UnGraphicBold \
		UnGungseo \
		UnPilgi \
		UnPilgiBold
FONTFILES=	${FONTLIST:S/$/.ttf/} fonts.dir fonts.scale

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
