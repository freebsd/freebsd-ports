# New ports collection makefile for:   cduce
# Date created:        Jun 9, 2005
# Whom:                Marwan Burelle <marwan.burelle@lri.fr>
#
# $FreeBSD$

PORTNAME=	cduce
PORTVERSION=	0.3.2
CATEGORIES=	lang
MASTER_SITES=	http://www.cduce.org/download/

MAINTAINER=	marwan.burelle@lri.fr
COMMENT=	An efficient XML centric functionnal programming language

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre-utf8
BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		${LOCALBASE}/lib/ocaml/site-lib/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		${LOCALBASE}/lib/ocaml/site-lib/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		${LOCALBASE}/lib/ocaml/site-lib/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

# Support for url via ftp/ocaml-ocurl
.if !defined(WITHOUT_OCURL)
BUILD_DEPENDS+=	${LOCALBASE}/lib/ocaml/site-lib/curl/curl.cmi:${PORTSDIR}/ftp/ocaml-ocurl
.endif

# Support for the PXP XML parser
.if defined(WITH_OCAML_EXPAT)
BUILD_DEPENDS+=${LOCALBASE}/lib/ocaml/site-lib/expat/expat.cmi:${PORTSDIR}/textproc/ocaml-expat
.else
BUILD_DEPENDS+=${LOCALBASE}/lib/ocaml/site-lib/pxp-engine/pxp_engine.cma:${PORTSDIR}/textproc/ocaml-pxp
.endif

# Configure : use ocamlopt and don't look for netclient or pxp_wlex
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-ocamlopt --without-netclient --without-pxp_wlex

# Be sure to not build ocurl support if WITHOUT_OCURL is defined,
# even if ocurl is present.
.if defined(WITHOUT_OCURL)
CONFIGURE_ARGS+=	--without-curl
.endif

# Be sure to build with PXP or expat but not both.
.if defined(WITH_OCAML_EXPAT)
CONFIGURE_ARGS+=	--with-expat --without-pxp
.else
CONFIGURE_ARGS+=	--without-expat --with-pxp
.endif

# Support for OCaml/CDuce interface
.if !defined(WITHOUT_MLIFACE)
CONFIGURE_ARGS+=	--mliface=${LOCALBASE}/lib/ocaml/compiler-lib
.endif

USE_GMAKE=	yes

ALL_TARGET=	all

INSTALL_TARGET=	install

MAKE_ENV=	OCAMLFIND_DESTDIR="${PREFIX}/lib/ocaml/site-lib"

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PORTNAME}
ALL_TARGET+=		doc
INSTALL_TARGET+=	install_doc
PORTDOCS=		*
.endif

MAN1=		cduce.1 cdo2ml.1 cduce_mktop.1

PKGDEINSTALL=	${PKGINSTALL}
FINDLIB_PKGNAME=${PORTNAME}

PLIST_FILES=	bin/cduce

.if !defined(WITHOUT_MLIFACE)
PLIST_FILES+=	bin/cdo2ml bin/mlcduce_wrapper bin/cduce_mktop
.endif

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/${FINDLIB_PKGNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/${FINDLIB_PKGNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove ${FINDLIB_PKGNAME} 2>/dev/null || true" >> ${TMPPLIST}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if defined(WITH_OCAML_EXPAT)
	@${ECHO_CMD} "****************************************************************"
	@${ECHO_CMD} "* You choose Expat as XML parser, you may encounter some error *"
	@${ECHO_CMD} "* when loading XML files with external DTD.                    *"
	@${ECHO_CMD} "****************************************************************"
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may define the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITHOUT_CURL		Disable url support via ftp/ocaml-ocurl (=> no url support)"
	@${ECHO} "	WITH_OCAML_EXPAT	Enable support for the Expat XML parser."
	@${ECHO} "	WITHOUT_MLIFACE		Disable building OCaml/CDuce interface."
	@${ECHO} ""

.include <bsd.port.mk>
