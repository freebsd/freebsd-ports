# ports collection makefile for:	dap
# Date created:				23 August 1998
# Whom:					yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	dap
PORTVERSION=	2.1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.cee.hw.ac.uk/~richardk/downloads/
EXTRACT_SUFX=.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio sample editing and processing suite

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

MAKEFILE=	Makefile.linux
USE_X_PREFIX=	yes
USE_XPM=	yes

MAKE_ENV+=	OTHER_INCLUDE_DIR=. OTHER_LIBRARY_DIR=.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/DAP/
	${INSTALL_MAN} ${WRKSRC}/COPYING ${WRKSRC}/README \
		${WRKSRC}/THANKS ${WRKSRC}/TODO ${PREFIX}/share/doc/DAP/
.endif

.include <bsd.port.mk>
