# New ports collection makefile for:	truereality
# Date Created:		28 November 1999
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	truereality
PORTVERSION=	${DATE}
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.emuhq.com/emulators/
DISTNAME=	TrueReality-${PORTVERSION}

MAINTAINER=	lioux@linf.unb.br

USE_GMAKE=	yes
USE_XLIB=	yes

MAKE_ARGS=	X11BASE=${X11BASE}

WRKSRC=		${WRKDIR}/TrueReality/Source

DATE=		1999121400

.include <bsd.port.pre.mk>

post-patch:
.if ${ARCH} == "alpha"
	@(cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/patch-alpha || ${ECHO})
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/TrueReality ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bin/TrueReality ${PREFIX}/bin/truereality

.include <bsd.port.post.mk>
