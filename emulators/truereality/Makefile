# New ports collection makefile for:	truereality
# Date Created:		28 November 1999
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	truereality
PORTVERSION=	${DATE}
CATEGORIES=	emulators devel
MASTER_SITES=	ftp://ftp.mayn.de/pub/unix/emulators/console/n64/
DISTNAME=	TrueReality-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

USE_GMAKE=	yes
USE_XLIB=	yes

MAKE_ARGS=	X11BASE=${X11BASE}

WRKSRC=		${WRKDIR}/TrueReality/Source

DATE=		1999121400

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
post-patch:
	@cd ${WRKSRC} ; ${PATCH} < ${PATCHDIR}/extra-patch-alpha
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/TrueReality ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bin/TrueReality ${PREFIX}/bin/truereality

.include <bsd.port.post.mk>
