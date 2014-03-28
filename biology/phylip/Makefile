# Created by: dbader@eece.unm.edu
# $FreeBSD$

PORTNAME=	phylip
PORTVERSION=	3.695
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/phylip/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Phylogeny Inference Package

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

USE_XORG=	x11 xaw xt
USES=		gmake
MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DUNX" \
		DFLAGS="${CFLAGS} -DX -I${LOCALBASE}/include" \
		DLIBS="-L${LOCALBASE}/lib -lX11 -lXaw -lXt -lm"
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-install:
	@(cd ${WRKSRC}/src && ${STRIP_CMD} libdrawtree.so libdrawgram.so)

post-install:
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -not -name '*.jar' \
		-not -name '*.unx' -not -name 'font*' -not -name '*.so' \
		-exec ${INSTALL_PROGRAM} "{}" "${STAGEDIR}${PREFIX}/bin/{}" \;
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -name "*.so" \
		-exec ${INSTALL_DATA} "{}" "${STAGEDIR}${PREFIX}/lib/{}" \;
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -name 'font*' \
		-exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/{}" \;
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/exe && ${COPYTREE_SHARE} testdata ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
