# New ports collection makefile for:   cduce
# Date created:        Jun 9, 2005
# Whom:                Marwan Burelle <marwan.burelle@lri.fr>
#
# $FreeBSD$

PORTNAME=	cduce
PORTVERSION=	0.5.2.1
CATEGORIES=	lang
MASTER_SITES=	http://www.cduce.org/download/ \
		ftp://ftp.stack.nl/pub/users/johans/cduce/

MAINTAINER=	johans@stack.nl
COMMENT=	An efficient XML centric functionnal programming language

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	${SITELIBDIR}/ulex/ulexing.a:${PORTSDIR}/devel/ocaml-ulex \
		${SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		${SITELIBDIR}/netstring/netstring.a:${PORTSDIR}/www/ocaml-net

USE_OCAML=	true
USE_OCAML_FINDLIB=	true
USE_OCAML_LDCONFIG=	true

OPTIONS=	OCURL		"Enable url support via ftp/ocaml-ocurl" Off \
		OCAML_EXPAT	"Enable support for the Expat XML parser" Off \
		MLIFACE		"Enable building OCaml/CDuce interface" On

USE_GMAKE=	yes
ALL_TARGET=	all
INSTALL_TARGET=	install
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-ocamlopt --with-cgi --without-netclient --without-pxp_wlex
SITELIBDIR=	${LOCALBASE}/${OCAML_SITELIBDIR}
WRKSRC=		${WRKDIR}/${DISTNAME:R}

MAN1=		cduce.1 cduce_mktop.1 dtd2cduce.1

PLIST_FILES=	bin/cduce bin/dtd2cduce

.include <bsd.port.pre.mk>

# Support for url via ftp/ocaml-ocurl
.if defined(WITH_OCURL)
BUILD_DEPENDS+=	${SITELIBDIR}/curl/curl.cmi:${PORTSDIR}/ftp/ocaml-ocurl
.endif

# Support for the PXP XML parser
.if defined(WITH_OCAML_EXPAT)
CONFIGURE_ARGS+=	--with-expat --without-pxp
BUILD_DEPENDS+=		${SITELIBDIR}/expat/expat.cmi:${PORTSDIR}/textproc/ocaml-expat
.else
CONFIGURE_ARGS+=	--without-expat --with-pxp
BUILD_DEPENDS+=		${SITELIBDIR}/pxp-engine/pxp_engine.cma:${PORTSDIR}/textproc/ocaml-pxp
.endif

# Be sure to not build ocurl support if WITH_OCURL is not defined,
# even if ocurl is present.
.if !defined(WITH_OCURL)
CONFIGURE_ARGS+=	--without-curl
.endif

# Support for OCaml/CDuce interface
.if !defined(WITHOUT_MLIFACE)
PLIST_FILES+=	bin/cduce_mktop
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/lang/ocaml:patch
CONFIGURE_ARGS+=	--mliface=`cd ${PORTSDIR}/lang/ocaml; ${MAKE} -V WRKSRC`
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PORTNAME}
ALL_TARGET+=		doc
INSTALL_TARGET+=	install_doc
PORTDOCS=		*
.endif

post-install:
.if defined(WITH_OCAML_EXPAT)
	@${ECHO_CMD} "****************************************************************"
	@${ECHO_CMD} "* You choose Expat as XML parser, you may encounter some error *"
	@${ECHO_CMD} "* when loading XML files with external DTD.                    *"
	@${ECHO_CMD} "****************************************************************"
.endif

.include <bsd.port.post.mk>
