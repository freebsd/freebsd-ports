# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	annexlib
PORTVERSION=	0.13.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://raevnos.pennmush.org/code/extlib/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	OCaml subroutines collection

LICENSE=	LGPL21

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:devel/ocaml-pcre
RUN_DEPENDS=	${SA_DIR}/pcre/pcre.a:devel/ocaml-pcre

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all opt
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

post-install:
	cd  ${STAGEDIR}${PREFIX} && \
	    ${STRIP_CMD} lib/ocaml/site-lib/annexlib/dllannexlib_stubs.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/html/* \
	    ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
