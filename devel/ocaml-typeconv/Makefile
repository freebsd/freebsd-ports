# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	type-conv
PORTVERSION=	109.60.01
CATEGORIES=	devel
MASTER_SITES=	https://ocaml.janestreet.com/ocaml-core/${PORTVERSION:R}.00/individual/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME:S,-,_,}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Type conversion routines for OCaml

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_CAMLP4=yes
USE_OCAMLFIND_PLIST=yes
OCAML_PKGDIRS=	${PORTNAME:S,-,_,}

USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX} --disable-docs
MAKE_JOBS_UNSAFE=yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME:S,-,_,}

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CHANGES.txt README.md
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
