# New ports collection makefile for:   ocaml-equeue
# Date created:        21 July 2004
# Whom:                David JULIEN
#
# $FreeBSD$
#

PORTNAME=	equeue
PORTVERSION=	2.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	david.julien@gmail.com
COMMENT=	The Equeue library for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GMAKE=	yes
MAKE_FLAGS=	PACKAGES=	# If defined, would be used by ocamlfind
HAS_CONFIGURE=	yes

ALL_TARGET=	all opt

PKGDEINSTALL=	${PKGINSTALL}

.if defined(WITH_EQUEUE_TCL)
BUILD_DEPENDS+=		${LOCALBASE}/include/tcl8.4:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	-with-equeue-tcl -equeue-tcl-defs "-I${LOCALBASE}/include/tcl8.4" -equeue-tcl-libs "-L${LOCALBASE}/lib -ltcl84"
PLIST_SUB+=		TCL=""
.else
PLIST_SUB+=		TCL="@comment "
.endif

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
