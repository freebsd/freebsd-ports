PORTNAME=	asdf
DISTVERSION=	3.3.4.7
PORTEPOCH=	2
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	System definition facility for Common Lisp

LICENSE=	MIT

USES=		gmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.common-lisp.net
GL_COMMIT=	a58828745a610c1af841a86587ba197707c89eb3

ALL_TARGET=	build/asdf.lisp
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}
	@${MKDIR} ${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/build/asdf.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/*.asd ${STAGEDIR}${ASDF_PATHNAME}
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/asdf.asd ${STAGEDIR}${ASDF_REGISTRY}
	${SED}	-i '' -e 's|%%PREFIX%%|${PREFIX}|' ${STAGEDIR}${ASDF_PATHNAME}/asdf.lisp
	${SED}	-e 's|%%ASDF_PATHNAME%%|${ASDF_PATHNAME}/asdf|' \
		-e 's|%%ASDF_REGISTRY%%|${ASDF_REGISTRY}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/asdf-init.lisp > \
		${STAGEDIR}${PREFIX}/etc/asdf-init.lisp.default

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.cl-asdf.mk>
.include <bsd.port.mk>
