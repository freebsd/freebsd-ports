# Created by: Marwan BURELLE <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	ocurl
PORTVERSION=	0.8.2
CATEGORIES=	ftp
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Interface for OCaml to the curl lib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ocamlc:lang/ocaml \
		ocamlfind:devel/ocaml-findlib
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake
GNU_CONFIGURE=	yes
#CONFIGURE_ARGS+="--with-findlib"

USE_GITHUB=	yes
GH_ACCOUNT=	ygrek

USE_OCAML=		yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
OCAML_PKGDIRS=		curl

OPTIONS_DEFINE=		LWT
OPTIONS_DEFAULT=	LWT
OPTIONS_SUB=		yes
LWT_DESC=		Include threading support (ocaml-lwt)
LWT_RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/lwt/lwt.a:devel/ocaml-lwt
LWT_BUILD_DEPENDS=	${LWT_RUN_DEPENDS}

post-install-LWT-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/curl/curl_lwt.cmxs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/curl/dllcurl-helper.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/curl/curl.cmxs \

post-configure-LWT-off:
# Override auto-detection

	${REINPLACE_CMD} 's/(lwt,no)/(no,no)/' ${WRKSRC}/Makefile \
		${WRKSRC}/examples/Makefile

.include <bsd.port.mk>
