# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	deriving-ocsigen
PORTVERSION=	0.3c
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://ocsigen.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Function derivation library

BROKEN=		old version, incompatible with modern OCaml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

USES=		gmake

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/deriving-ocsigen/*.cmxs

.include <bsd.port.mk>
