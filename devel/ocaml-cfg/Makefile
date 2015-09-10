# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	cfg
PORTVERSION=	2.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulation of context-free grammars

LICENSE=	LGPL21

BUILD_DEPENDS=	menhir:${PORTSDIR}/devel/menhir

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_GITHUB=	yes
GH_ACCOUNT=	mmottl

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes
USE_OCAML_WASH=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} --disable-docs --disable-examples
MAKE_JOBS_UNSAFE=yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS.txt CHANGES.txt README.md ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
