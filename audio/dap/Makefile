# ports collection makefile for:	dap
# Version required:			1.3b
# Date created:				23 August 1998
# Whom:					yoshiaki Uchikawa
#
# $Id: Makefile,v 1.1.1.1 1998/09/16 12:54:00 vanilla Exp $
#

DISTNAME=	DAPSource
PKGNAME=	dap-1.3b
CATEGORIES=	audio
MASTER_SITES=	http://www.cee.hw.ac.uk/~richardk/

MAINTAINER=	yoshiaki@kt.rim.or.jp

BROKEN_ELF=	xforms is a.out only

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms

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
