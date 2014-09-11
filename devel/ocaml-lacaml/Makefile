# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	lacaml
PORTVERSION=	7.1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GH
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml interface to BLAS and LAPACK libraries

LICENSE=	LGPL21

LIB_DEPENDS=	libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION:S/^/v/}
GH_COMMIT=	7731438

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes
USE_OCAML_LDCONFIG=yes
USE_OCAML_WASH=	yes
OCAMLFIND_LDCONF=ignore

USES=		fortran
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} --disable-docs --disable-examples \
		--override conf_ccopt "${CFLAGS}" \
		--override conf_cclib "${LDFLAGS:S,^.*[[:space:]],,}"
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-fPIC -DEXTERNAL_EXP10
LDFLAGS+=	-L${LOCALBASE}/lib -lblas -llapack

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS.txt CHANGES.txt README.md TODO.md
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lacaml/*.cmxs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lacaml/*.so

.include <bsd.port.mk>
