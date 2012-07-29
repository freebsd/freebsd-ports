# New ports collection makefile for:   cduce
# Date created:        Jun 9, 2005
# Whom:                Marwan Burelle <marwan.burelle@lri.fr>
#
# $FreeBSD$

PORTNAME=	cduce
PORTVERSION=	0.5.5
CATEGORIES=	lang
MASTER_SITES=	http://www.cduce.org/download/ \
		ftp://ftp.stack.nl/pub/users/johans/cduce/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Efficient XML centric functional programming language

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	${SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		${SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		${SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

USE_OCAML=	true
USE_OCAML_FINDLIB=	true
USE_OCAML_LDCONFIG=	true

OPTIONS_DEFINE=	OCURL OCAML_EXPAT MLIFACE
OPTIONS_DEFAULT=MLIFACE
OCURL_DESC=		Enable url support via ftp/ocaml-ocurl
OCAML_EXPAT_DESC=	Enable support for the Expat XML parser
MLIFACE_DESC=		Enable building OCaml/CDuce interface

USE_GMAKE=	yes
ALL_TARGET=	all
INSTALL_TARGET=	install_bin install_lib
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-ocamlopt --without-cgi --without-netclient --without-pxp_wlex --docdir=${DOCSDIR}
SITELIBDIR=	${LOCALBASE}/${OCAML_SITELIBDIR}

MAN1=		cduce.1 cduce_mktop.1 dtd2cduce.1

PLIST_FILES=	bin/cduce

.include <bsd.port.options.mk>

# Support for url via ftp/ocaml-ocurl
.if ${PORT_OPTIONS:MOCURL}
BUILD_DEPENDS+=	${SITELIBDIR}/curl/curl.cmi:${PORTSDIR}/ftp/ocaml-ocurl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

# Support for the PXP XML parser
.if ${PORT_OPTIONS:MOCAML_EXPAT}
CONFIGURE_ARGS+=	--with-expat --without-pxp
BUILD_DEPENDS+=		${SITELIBDIR}/expat/expat.cmi:${PORTSDIR}/textproc/ocaml-expat
.else
CONFIGURE_ARGS+=	--without-expat --with-pxp
BUILD_DEPENDS+=		${SITELIBDIR}/pxp-engine/pxp_engine.cma:${PORTSDIR}/textproc/ocaml-pxp
.endif

# Support for OCaml/CDuce interface
.if ${PORT_OPTIONS:MMLIFACE}
PLIST_FILES+=	bin/cduce_mktop
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/lang/ocaml:patch
CONFIGURE_ARGS+=	--mliface=`cd ${PORTSDIR}/lang/ocaml; ${MAKE} -V WRKSRC`
.endif

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=		doc
INSTALL_TARGET+=	install_doc
PORTDOCS=		*
.endif

post-patch:
	${REINPLACE_CMD} 's/-linkpkg/& -thread/' \
		${WRKSRC}/Makefile ${WRKSRC}/configure.ml

post-install:
.if ${PORT_OPTIONS:MOCAML_EXPAT}
	@${ECHO_CMD} "****************************************************************"
	@${ECHO_CMD} "* You choose Expat as XML parser, you may encounter some error *"
	@${ECHO_CMD} "* when loading XML files with external DTD.                    *"
	@${ECHO_CMD} "****************************************************************"
.endif
.if empty(PORT_OPTIONS:MDOCS)
. for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${MANPREFIX}/man/man${i:E}/
. endfor
.endif

.include <bsd.port.mk>
