# New ports collection makefile for:	truereality
# Date Created:		28 November 1999
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	truereality
PORTVERSION=	1999062900
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.emuhq.com/emulators/
DISTNAME=	TrueReality-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@linf.unb.br

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3 \
		GLU.14:${PORTSDIR}/graphics/Mesa3 \
		X11.6:${PORTSDIR}/x11/XFree86 \
		Xext.6:${PORTSDIR}/x11/XFree86

USE_GMAKE=	yes
USE_XLIB=	yes

WRKSRC=		${WRKDIR}/TrueReality/Source

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/TrueReality ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bin/TrueReality ${PREFIX}/bin/truereality

.include <bsd.port.mk>
