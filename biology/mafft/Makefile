PORTNAME=	mafft
PORTVERSION=	7.267
CATEGORIES=	biology
MASTER_SITES=	http://mafft.cbrc.jp/alignment/software/
DISTNAME=	${PORTNAME}-${PORTVERSION}-without-extensions-src

MAINTAINER=	cartwright@asu.edu
COMMENT=	Multiple alignment program for amino acid or nucleotide sequences

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-without-extensions
BUILD_WRKSRC=	${WRKSRC}/core
INSTALL_WRKSRC=	${WRKSRC}/core

USES=		gmake shebangfix tar:tgz

SHEBANG_FILES=	core/*.tmpl

MAKE_ENV=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		MKDIR="${MKDIR}" \
		LN="${LN}"

.include <bsd.port.options.mk>

post-patch:
.if ${ARCH} == sparc64
	@${REINPLACE_CMD} -e 's|ENABLE_MULTITHREAD = -Denablemultithread||' \
		${BUILD_WRKSRC}/Makefile
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
