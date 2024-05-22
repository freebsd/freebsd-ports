PORTNAME=	base64
PORTVERSION=	3.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	converters
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Base64 encoding and decoding in OCaml
WWW=		https://github.com/mirage/ocaml-base64

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/bos/META:devel/ocaml-bos \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/rresult/META:devel/ocaml-rresult
RUN_DEPENDS=	${SA_DIR}/bos/META:devel/ocaml-bos \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/rresult/META:devel/ocaml-rresult

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	mirage
GH_PROJECT=	ocaml-base64
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@(cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}; \
	${STRIP_CMD} \
		base64/base64.cmxs \
		base64/rfc2045/base64_rfc2045.cmxs)
	# this port never shipped stublibs
	# cleanup from older port's wrong USE_OCAML_LDCONFIG
	@${ECHO_CMD} @postexec ${SED} -i "''" -e \
		"'/^${PREFIX:S#/#\/#g}\/${OCAML_SITELIBDIR:S#/#\/#g}\/base64$$/d'" \
		%D/${OCAML_LDCONF}  >> ${TMPPLIST}

.include <bsd.port.mk>
