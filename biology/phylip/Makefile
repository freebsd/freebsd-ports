# New ports collection makefile for:	phylip
# Date created:				4 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	phylip
PORTVERSION=	3.68
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/phylip/ \
		http://bioinformatics.weizmann.ac.il/software/linkage_and_mapping/phylip/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Phylogeny Inference Package

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_XORG=	x11 xaw xt
USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	CC="${CC} ${CFLAGS}" \
		DC="${CC} -DX ${CFLAGS}" \
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
