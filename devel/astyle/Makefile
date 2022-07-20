PORTNAME=	astyle
PORTVERSION=	3.1
PORTREVISION=	3
CATEGORIES=	devel textproc
MASTER_SITES=	SF/astyle/astyle/astyle%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_linux

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code indenter and formatter for C, C++, C\#, and Java

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/astyle/LICENSE.md

USES=		compiler:c++11-lang dos2unix gmake

ALL_TARGET=	astyle
WRKSRC=		${WRKDIR}/astyle/build/${CHOSEN_COMPILER_TYPE}

DOS2UNIX_GLOB=	*.ini

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|%%CXX%%|${CXX}|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/astyle ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/doc/* ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/astyle/file/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
