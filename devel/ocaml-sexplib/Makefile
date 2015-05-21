# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	sexplib
PORTVERSION=	111.03.00
CATEGORIES=	devel
MASTER_SITES=	https://ocaml.janestreet.com/ocaml-core/${PORTVERSION}/individual/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml library for working with S-expressions

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi

BUILD_DEPENDS=	ocaml-type-conv>0:${PORTSDIR}/devel/ocaml-typeconv
RUN_DEPENDS=	ocaml-type-conv>0:${PORTSDIR}/devel/ocaml-typeconv

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_CAMLP4=yes
USE_OCAMLFIND_PLIST=yes
OCAML_PKGDIRS=	${PORTNAME} ${PORTNAME}_num ${PORTNAME}_unix

USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} --disable-docs
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CHANGES.txt README.md
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
