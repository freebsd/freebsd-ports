PORTNAME=	ficl
PORTVERSION=	4.1.0
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-all/${PORTNAME}${PORTVERSION:C/([[:digit:]]+\.[[:digit:]]+)\.0/\1/}

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Forth Inspired Command Language

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${PATCHDIR}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	this port is not tested on anything other than i386 and amd64

USE_LDCONFIG=	YES

ALL_TARGET=	lib ${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} include/ficl.h include/ficlcompatibility.h \
		include/ficllocal.h include/ficlplatform/unix.h \
		include/ficltokens.h lib/lib${PORTNAME}.so \
		lib/lib${PORTNAME}.so.${PORTVERSION} lib/lib${PORTNAME}.a

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}*.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -sf lib${PORTNAME}.so.${PORTVERSION} lib${PORTNAME}.so

	@${MKDIR} ${STAGEDIR}${PREFIX}/include/ficlplatform
	${INSTALL_DATA} ${WRKSRC}/ficlplatform/unix.h ${STAGEDIR}${PREFIX}/include/ficlplatform

	@${MKDIR} ${STAGEDIR}${DATADIR}/ficlplatform
	${INSTALL_DATA} ${WRKSRC}/ficlplatform/unix.c ${STAGEDIR}${DATADIR}/ficlplatform
	(cd ${WRKSRC}/contrib && ${COPYTREE_SHARE} xclasses ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} softcore ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} test ${STAGEDIR}${DATADIR})

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.ico ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} articles ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} graphics ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
