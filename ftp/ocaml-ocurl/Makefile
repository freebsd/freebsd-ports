# Created by: Marwan BURELLE <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	ocurl
PORTVERSION=	0.7.7
CATEGORIES=	ftp
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/1612/ \
		http://ygrek.org.ua/p/release/ocurl/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Interface for OCaml to the curl lib

BUILD_DEPENDS=	ocamlc:lang/ocaml \
		ocamlfind:devel/ocaml-findlib
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-findlib"
MAKE_JOBS_UNSAFE=	yes

USE_OCAML=		yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
OCAML_PKGDIRS=		curl

OPTIONS_DEFINE=	LWT
OPTIONS_DEFAULT=LWT
OPTIONS_SUB=	yes
LWT_DESC=	Include threading support (ocaml-lwt)
LWT_RUN_DEPENDS=${LOCALBASE}/${OCAML_SITELIBDIR}/lwt/lwt.a:devel/ocaml-lwt
LWT_BUILD_DEPENDS=${LWT_RUN_DEPENDS}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/curl/dllcurl-helper.so

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MLWT}
# Override auto-detection
post-configure:
	${REINPLACE_CMD} 's/(lwt,no)/(no,no)/' ${WRKSRC}/Makefile \
		${WRKSRC}/examples/Makefile
.endif

.include <bsd.port.mk>
