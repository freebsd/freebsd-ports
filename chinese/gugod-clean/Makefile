# New ports collection makefile for:	gugod-clean
# Date Created:                         21 Jun 2001
# Whom:                                 Kang-min Liu <gugod@gugod.org>
# $FreeBSD$

PORTNAME=	gugod-clean
PORTVERSION=	1.3
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/gugod/

MAINTAINER=	gugod@gugod.org

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

FONTFILES=	gugod16.bdf gugod18.bdf gugod20.bdf gugod22.bdf
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
SHAREMODE=	644
XFONTDIR=	${X11BASE}/lib/X11/fonts/local

do-install:
	@${MKDIR} ${XFONTDIR}
.for i in ${FONTFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${XFONTDIR}
.endfor
	@cd ${XFONTDIR} ; mkfontdir

.include <bsd.port.post.mk>
