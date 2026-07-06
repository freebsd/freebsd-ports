PORTNAME=	magic
DISTVERSION=	0.7.4
CATEGORIES=	devel
MASTER_SITES=	https://github.com/Chris00/${PKGNAMEPREFIX}${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OCaml binding for libmagic(3)
WWW=		https://github.com/Chris00/ocaml-magic

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ocaml:findlib,ldconfig

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes

ALL_TARGET=	doc examples
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/magic/dllmagic_stubs.so

post-install-DOCS-on:
	cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/examples/file ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ml ${WRKSRC}/examples/Makefile \
		 ${WRKSRC}/OCamlMakefile ${STAGEDIR}${EXAMPLESDIR}
	${REINPLACE_CMD} -e "/^export OCAMLMAKEFILE/s@../@@" \
		-e "/^export INCDIRS/s@=.*@= +site-lib/magic@" \
		${STAGEDIR}${EXAMPLESDIR}/Makefile

.include <bsd.port.mk>
