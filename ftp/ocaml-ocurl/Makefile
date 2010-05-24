# Ports collection makefile for:	ocurl
# Date created:			Aug 6, 2004
# Whom:				Marwan BURELLE <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	ocurl
PORTVERSION=	0.5.3
CATEGORIES=	ftp
MASTER_SITES=	SF
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	An interface for OCaml to the curl lib

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-findlib"
MAKE_JOBS_UNSAFE=	yes

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes

.include <bsd.port.mk>
