# Created by: Kang-min Liu <gugod@gugod.org>
# $FreeBSD$

PORTNAME=	gugod-clean
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/gugod/

MAINTAINER=	gugod@gugod.org
COMMENT=	Pretty font modifyed from X11 schumacher-clean that match kcfonts

RUN_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

FONTFILES=	gugod16.bdf gugod18.bdf gugod20.bdf gugod22.bdf

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
SHAREMODE=	644
XFONTDIR=	${LOCALBASE}/lib/X11/fonts/local

do-install:
	@${MKDIR} ${STAGEDIR}${XFONTDIR}
.for i in ${FONTFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${XFONTDIR}
.endfor
	@cd ${STAGEDIR}${XFONTDIR} ; mkfontdir

.include <bsd.port.mk>
