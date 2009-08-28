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
DISTNAME=	DFSongSd.ttf
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese (HKSCS-2001 + CJK A) TrueType fonts

RESTRICTED=	"No redistribution or commercial use is allowed."
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

TTF_DEFAULT=	${DISTFILES}
TTF=		${DISTFILES}

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}

do-fetch:
.if !exists (${DISTDIR}/${DISTNAME})
ECHO_MSG=/usr/bin/printf
IGNORE=\'s distfile must be downloaded manually from\n\
\ \ \ \ \ http://glyph.iso10646hk.net/chinese/download_001.html If you agree\n\
\ \ \ \ \ with the terms given in the above page, please download ${DISTNAME},\n\
\ \ \ \ \ put it into ${DISTDIR} and run \'make\' again\n\n.
.endif

do-install:
	@${MKDIR} ${FONTSDIR}
.for ttf in ${TTF}
	${INSTALL_DATA} ${DISTDIR}/${TTF} ${FONTSDIR}
.endfor

.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
