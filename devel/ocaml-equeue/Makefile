# Created by: David JULIEN
# $FreeBSD$

PORTNAME=	equeue
PORTVERSION=	2.1.4
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	michipili@gmail.com
COMMENT=	The Equeue library for OCaml

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

DEPRECATED=	Superseded by www/ocaml-net
EXPIRATION_DATE=2015-08-20

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=			gmake
USE_OCAML=		YES
USE_OCAML_FINDLIB=	YES
USE_OCAML_LDCONFIG=	YES
MAKE_FLAGS=		PACKAGES=	# If defined, would be used by ocamlfind
HAS_CONFIGURE=		YES

OCAML_LDLIBS=		${OCAML_SITELIBDIR}/${PORTNAME}
OCAML_LDLIBS+=		${OCAML_SITELIBDIR}/shell

ALL_TARGET=		all opt
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DOCS EQUEUE_TCL

EQUEUE_TCL_DESC=	Integration with the labltk event system

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEQUEUE_TCL}
USES+=			tcl
CONFIGURE_ARGS+=	-with-equeue-tcl
CONFIGURE_ARGS+=	-equeue-tcl-defs
CONFIGURE_ARGS+=	"-I${TCL_INCLUDEDIR}"
CONFIGURE_ARGS+=	-equeue-tcl-libs
CONFIGURE_ARGS+=	"-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER}"
PLIST_SUB+=		TCL=""
OCAML_LDLIBS+=		${OCAML_SITELIBDIR}/${PORTNAME}-tcl
.else
PLIST_SUB+=		TCL="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/examples/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
