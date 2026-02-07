PORTNAME=	magic
PORTVERSION=	0.7.3
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF/ocaml-${PORTNAME}/ocaml-${PORTNAME}/0.7
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml binding for libmagic(3)
WWW=		https://sourceforge.net/projects/ocaml-magic/

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/magic/dllmagic_stubs.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/file

.include <bsd.port.mk>
