# New ports collection makefile for:	ocamlduce
# Date created:				Feb 24, 2007
# Whom:					Jaap Boender <jaapb@kerguelen.rg>
#
# $FreeBSD$
#

PORTNAME=	ocamlduce
PORTVERSION=	3.11.1.0
CATEGORIES=	lang
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/225/

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Library to integrate XML features into OCaml

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/lang/ocaml:extract

BROKEN=		does not build

ALL_TARGET=	prepare config/Makefile world world.opt
INSTALL_TARGET=	installbyte installopt

.include <bsd.port.pre.mk>

OCAML_WRKSRC!=	(cd ${PORTSDIR}/lang/ocaml && ${MAKE} -V WRKSRC)

USE_GMAKE=	yes
USE_OCAML=	yes
MAKE_ENV+=	PORTSDIR="${PORTSDIR}" OCAML_SOURCE="${OCAML_WRKSRC}" BINDIR="${LOCALBASE}/bin" SA_DIR="${LOCALBASE}/lib/ocaml/site-lib"
OCAMLC_DEPEND=	ocaml>=3.11.1:${OCAMLC_PORT}
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_PLIST=	yes

.include <bsd.port.post.mk>
