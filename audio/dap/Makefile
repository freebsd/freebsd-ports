# ports collection makefile for:	dap
# Date created:				23 August 1998
# Whom:					yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	dap
PORTVERSION=	2.0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.cee.hw.ac.uk/~richardk/
DISTNAME=	DAPSource

MAINTAINER=	yoshiaki@kt.rim.or.jp

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms \
		Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/dap
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/DAP/
	${INSTALL_MAN} ${WRKSRC}/COPYING ${WRKSRC}/README \
		${WRKSRC}/THANKS ${WRKSRC}/TODO ${PREFIX}/share/doc/DAP/
.endif
post-install:
	strip ${PREFIX}/bin/DAP

.include <bsd.port.mk>
