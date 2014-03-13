# Created by: dbader@eece.unm.edu
# $FreeBSD$

PORTNAME=	phylip
PORTVERSION=	3.695
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/phylip/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Phylogeny Inference Package

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

OPTIONS_DEFINE=	DOCS EXAMPLES

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -not -name '*.jar' \
		-not -name '*.unx' -not -name 'font*' -not -name '*.so' \
		-exec ${INSTALL_PROGRAM} "{}" "${PREFIX}/bin/{}" \;
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -name "*.so" \
		-exec ${INSTALL_DATA} "{}" "${PREFIX}/lib/{}" \;
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -name 'font*' \
		-exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/exe && ${COPYTREE_SHARE} testdata ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
