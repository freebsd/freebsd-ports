# New ports collection makefile for:	gugod-clean
# Date Created:                         21 Jun 2001
# Whom:                                 Kang-min Liu <gugod@gugod.org>
# $FreeBSD$

PORTNAME=	gugod-clean
PORTVERSION=	1.1
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://gugod.org/pub/X/

MAINTAINER=	gugod@gugod.org

FONTFILES=	gugodclean.bdf g20.bdf
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
SHAREMODE=	644
XFONTDIR=	${X11BASE}/lib/X11/fonts/local

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${XFONTDIR}
.for i in ${FONTFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${XFONTDIR}
.endfor
	@cd ${XFONTDIR} ; mkfontdir

.include <bsd.port.post.mk>
