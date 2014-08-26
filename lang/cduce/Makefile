# Created by: Marwan Burelle <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	cduce
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.cduce.org/download/ \
		ftp://ftp.stack.nl/pub/users/johans/cduce/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Efficient XML centric functional programming language

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	${SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		${SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		${SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

USE_OCAML=		true
USE_OCAML_FINDLIB=	true
USE_OCAML_LDCONFIG=	true

OPTIONS_DEFINE=		OCURL MLIFACE DOCS
OPTIONS_DEFAULT=	MLIFACE PXP
OPTIONS_SINGLE=		XML
OPTIONS_SINGLE_XML=	EXPAT PXP
OPTIONS_SUB=		yes
OCURL_DESC=		Enable url support via ftp/ocaml-ocurl
OCURL_BUILD_DEPENDS=	${SITELIBDIR}/curl/curl.cmi:${PORTSDIR}/ftp/ocaml-ocurl
OCURL_CONFIGURE_WITH=	curl
EXPAT_DESC=		Enable support for the Expat XML parser
EXPAT_CONFIGURE_WITH=	expat
EXPAT_BUILD_DEPENDS=	${SITELIBDIR}/expat/expat.cmi:${PORTSDIR}/textproc/ocaml-expat
PXP_DESC=		Enable support for the PXP XML parser
PXP_CONFIGURE_WITH=	pxp
PXP_BUILD_DEPENDS=	${SITELIBDIR}/pxp-engine/pxp_engine.cma:${PORTSDIR}/textproc/ocaml-pxp
MLIFACE_DESC=		Enable building OCaml/CDuce interface
MLIFACE_BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/lang/ocaml:patch
MLIFACE_CONFIGURE_ON=	--mliface=`cd ${PORTSDIR}/lang/ocaml; ${MAKE} -V WRKSRC`

USES=		gmake
ALL_TARGET=	all doc
INSTALL_TARGET=	install_bin install_lib install_doc
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-ocamlopt --without-cgi --without-netclient --with-curl --without-pxp_wlex --docdir=${DOCSDIR}
SITELIBDIR=	${LOCALBASE}/${OCAML_SITELIBDIR}
MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} 's/-linkpkg/& -thread/' \
		${WRKSRC}/Makefile.distrib ${WRKSRC}/configure.ml

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cduce

.include <bsd.port.mk>
