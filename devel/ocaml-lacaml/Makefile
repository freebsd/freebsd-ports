# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	lacaml
PORTVERSION=	8.0.7
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/mmottl/lacaml/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml interface to BLAS and LAPACK libraries

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes
USE_OCAML_LDCONFIG=yes
USE_OCAML_WASH=	yes
OCAMLFIND_LDCONF=ignore

USES=		blaslapack fortran
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} --disable-docs --disable-examples \
		--override conf_ccopt "${CFLAGS}" \
		--override conf_cclib "${LDFLAGS}"
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-fPIC -DEXTERNAL_EXP10
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%BLASLIB%%|${BLASLIB}| ; \
		 s|%%LAPACKLIB%%|${LAPACKLIB}| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/myocamlbuild.ml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lacaml/*.cmxs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lacaml/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS.txt CHANGES.txt README.md TODO.md
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor

post-install-EXAMPLES-on:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
