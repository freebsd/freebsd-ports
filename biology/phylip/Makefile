# Created by: David A. Bader <dbader@eece.unm.edu>
# $FreeBSD$

PORTNAME=	phylip
PORTVERSION=	3.697
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/phylip/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Phylogeny Inference Package

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/src/COPYRIGHT

BUILD_DEPENDS=	bash:shells/bash

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

USES=		gmake xorg
USE_XORG=	x11 xaw xt
MAKEFILE=	Makefile.unx
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DUNX" \
		DFLAGS="${CFLAGS} -DX -I${LOCALBASE}/include" \
		DLIBS="-L${LOCALBASE}/lib -lX11 -lXaw -lXt -lm"
USE_LDCONFIG=	yes

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -not -name '*.jar' \
		-not -name '*.unx' -not -name 'font*' -not -name '*.so' \
		| ${XARGS} -J % ${INSTALL_PROGRAM} % ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -name "*.so" \
		| ${XARGS} -J % ${INSTALL_LIB} % ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/exe && \
		${FIND} . -maxdepth 1 -not -type d -name 'font*' \
		| ${XARGS} -J % ${INSTALL_DATA} % ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
