# Created by: Marwan BURELLE <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	ocurl
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/1463/ \
		http://ygrek.org.ua/p/release/ocurl/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Interface for OCaml to the curl lib

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-findlib"
MAKE_JOBS_UNSAFE=	yes

USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
OCAML_PKGDIRS=		curl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/curl/dllcurl-helper.so

.include <bsd.port.mk>
