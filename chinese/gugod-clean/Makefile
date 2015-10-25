# Created by: Kang-min Liu <gugod@gugod.org>
# $FreeBSD$

PORTNAME=	gugod-clean
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/gugod/

MAINTAINER=	gugod@gugod.org
COMMENT=	Pretty font modifyed from X11 schumacher-clean that match kcfonts

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USES=		fonts
RUN_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

FONTFILES=	gugod16.bdf gugod18.bdf gugod20.bdf gugod22.bdf

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
FONTNAME=	gugod

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FONTFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
