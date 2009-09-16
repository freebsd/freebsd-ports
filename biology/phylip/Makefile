# New ports collection makefile for:	phylip
# Date created:				4 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	phylip
PORTVERSION=	3.69
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/phylip/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Phylogeny Inference Package

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

USE_XORG=	x11 xaw xt
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		DFLAGS="${CFLAGS} -DX -I${LOCALBASE}/include" \
		DLIBS="-L${LOCALBASE}/lib -lX11 -lXaw -lXt -lm"

PORTDOCS=	*

post-install:
	@cd ${WRKSRC}/exe && \
		${FIND} . -not -type d -not -name 'font*' -exec ${INSTALL_PROGRAM} "{}" "${PREFIX}/bin/{}" \;
	${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/exe && \
		${FIND} . -not -type d -name 'font*' -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>
