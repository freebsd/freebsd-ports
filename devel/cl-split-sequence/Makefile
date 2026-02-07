PORTNAME=	split-sequence
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1-3
DISTVERSIONSUFFIX=	-g89a10b4
PORTEPOCH=	1
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Partitioning Common Lisp sequences
WWW=		https://www.cliki.net/SPLIT-SEQUENCE

LICENSE=	PD

USES=		cl
USE_GITHUB=	yes
GH_ACCOUNT=	sharplispers

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/*.lisp ${WRKSRC}/version.sexp \
		${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/split-sequence.asd ${STAGEDIR}${ASDF_PATHNAME}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/split-sequence.asd \
		${STAGEDIR}${ASDF_REGISTRY}

.include <bsd.port.mk>
