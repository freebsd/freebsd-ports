PORTNAME=	astyle
PORTVERSION=	3.6.10
CATEGORIES=	devel textproc
MASTER_SITES=	SF/astyle/astyle/astyle%20${PORTVERSION:R}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code indenter and formatter for C, C++, C\#, and Java
WWW=		https://astyle.sourceforge.net/ \
		https://gitlab.com/saalen/astyle

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE.md

USES=		compiler:c++11-lang dos2unix gmake tar:bz2

ALL_TARGET=	astyle
MAKE_ENV=	CXX="${CXX}"
WRKSRC_SUBDIR=	build/${CHOSEN_COMPILER_TYPE}

DOS2UNIX_GLOB=	*.ini

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/astyle ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../../doc/* ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/../../file/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
