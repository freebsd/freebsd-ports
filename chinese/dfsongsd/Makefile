# New ports collection makefile for:	DynaComware DFSongSd
# Date created:		2005/05/08
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	dfsongsd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	# empty
DISTNAME=	DFSongSd
EXTRACT_SUFX=	.ttf
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese (HKSCS-2001 + CJK A) TrueType fonts

RESTRICTED=	No redistribution or commercial use is allowed
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

TTF_DEFAULT=	${DISTFILES}
TTF=		${DISTFILES}

.include <bsd.port.pre.mk>

.if !exists (${DISTDIR}/${DISTNAME})
IGNORE=	distfile must be downloaded manually from http://glyph.iso10646hk.net/chinese/download_001.jsp.  Please download ${DISTNAME} into ${DISTDIR}
.endif

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	@${MKDIR} ${FONTSDIR}
.for ttf in ${TTF}
	${INSTALL_DATA} ${DISTDIR}/${ttf} ${FONTSDIR}
.endfor

.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
