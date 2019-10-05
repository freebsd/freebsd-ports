# $FreeBSD$

PORTNAME=	mothur
DISTVERSIONPREFIX=	v
DISTVERSION=	1.43.0
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for bioinformatics of the microbial ecology community

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake localbase readline shebangfix
SHEBANG_FILES=	source/uchime_src/mk
USE_GITHUB=	yes
ALL_TARGET=	${PORTNAME}

BINARY_ALIAS=	g++=${CXX}

EXES=		${PORTNAME} uchime

PLIST_FILES=	${EXES:S/^/bin\//}

do-install: # https://github.com/mothur/mothur/issues/615
.for e in ${EXES}
	${INSTALL_PROGRAM} ${WRKSRC}/${e} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
