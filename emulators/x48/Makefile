# New ports collection makefile for:	x48
# Date created:				Thu Oct 24 13:10:59 CDT 1996
# Whom:					Eric L. Hernes <erich@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x48
PORTVERSION=	0.6.3
CATEGORIES=	emulators math
MASTER_SITES=	BERLIOS
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		x48-gxrom-r${EXTRACT_SUFX} x48-sxrom-e${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An HP48 SX/GX graphic calculator emulator

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LIBS=-lutil
USE_GMAKE=	yes
USE_XORG=	x11 xext xt

PORTDOCS=	ChangeLog README

post-extract: .SILENT
# Extract official HP ROM images for GX/SX
	cd ${WRKSRC} && ${TAR} -zxf ${DISTDIR}/x48-gxrom-r${EXTRACT_SUFX}
	${MV} ${WRKSRC}/.hp48/rom ${WRKSRC}/gxrom-r
	cd ${WRKSRC} && ${TAR} -zxf ${DISTDIR}/x48-sxrom-e${EXTRACT_SUFX}
	${MV} ${WRKSRC}/.hp48/rom ${WRKSRC}/sxrom-e

post-patch:
# Prefer GX Revision R ROM by default
	@${REINPLACE_CMD} -e 's+rom\.dump+${DATADIR}/gxrom-r+' \
		${WRKSRC}/src/X48.ad

do-install:
.for p in x48 dump2rom checkrom mkcard
	${INSTALL_PROGRAM} ${WRKSRC}/src/${p} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/X48.ad ${PREFIX}/lib/X11/app-defaults/X48
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/??rom-? ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S+^+${WRKSRC}/+} ${DOCSDIR}
.endif

.include <bsd.port.mk>
