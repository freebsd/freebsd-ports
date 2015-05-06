# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	lacaml
PORTVERSION=	7.1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
MASTER_SITES=	GH
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml interface to BLAS and LAPACK libraries

LICENSE=	LGPL21

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl

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
		--override conf_cclib "${LDFLAGS:S,^.*[[:space:]],,}"
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-fPIC -DEXTERNAL_EXP10
LDFLAGS+=	-L${LOCALBASE}/lib ${BLASLIB} ${LAPACKLIB}

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
