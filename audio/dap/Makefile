# ports collection makefile for:	dap
# Date created:				23 August 1998
# Whom:					yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	dap
PORTVERSION=	2.1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.cee.hw.ac.uk/~richardk/downloads/
EXTRACT_SUFX=.tgz

MAINTAINER=	yoshiaki@kt.rim.or.jp

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

MAKEFILE=	Makefile.linux
USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/DAP/
	${INSTALL_MAN} ${WRKSRC}/COPYING ${WRKSRC}/README \
		${WRKSRC}/THANKS ${WRKSRC}/TODO ${PREFIX}/share/doc/DAP/
.endif

.include <bsd.port.mk>
