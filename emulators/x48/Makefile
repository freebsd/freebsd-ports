# New ports collection makefile for:	x48
# Date created:				Thu Oct 24 13:10:59 CDT 1996
# Whom:					Eric L. Hernes <erich@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x48
PORTVERSION=	0.4.3
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		x48-gxrom-r${EXTRACT_SUFX} x48-sxrom-e${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An HP48 SX/GX calculator emulator

USE_IMAKE=	yes
USE_XORG=	x11 xext
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.pre.mk>

post-extract: .SILENT
	cd ${WRKSRC} && ${TAR} -zxf ${DISTDIR}/x48-gxrom-r${EXTRACT_SUFX}
	${MV} ${WRKSRC}/.hp48/rom ${WRKSRC}/gxrom-r
	cd ${WRKSRC} && ${TAR} -zxf ${DISTDIR}/x48-sxrom-e${EXTRACT_SUFX}
	${MV} ${WRKSRC}/.hp48/rom ${WRKSRC}/sxrom-e

post-patch:
	@${REINPLACE_CMD} -e 's+rom.dump+${DATADIR}/gxrom-r+' \
		${WRKSRC}/src/X48.ad
	@${REINPLACE_CMD} -e 's+cuaa+cuad+' ${WRKSRC}/src/X48.ad

do-install:
.for p in x48 dump2rom checkrom mkcard
	${INSTALL_PROGRAM} ${WRKSRC}/src/${p} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/X48.ad ${PREFIX}/lib/X11/app-defaults/X48
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/??rom-? ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README doc/CARDS.doc doc/ROMDump.doc
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
