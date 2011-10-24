# New ports collection makefile for:   ocaml-equeue
# Date created:        21 July 2004
# Whom:                David JULIEN
#
# $FreeBSD$
#

PORTNAME=	equeue
PORTVERSION=	2.1.4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
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
MAKE_JOBS_UNSAFE=	yes

PKGDEINSTALL=	${PKGINSTALL}

.if defined(WITH_EQUEUE_TCL)
USE_TCL=	84+
CONFIGURE_ARGS+=	-with-equeue-tcl -equeue-tcl-defs "-I${TCL_INCLUDEDIR}" -equeue-tcl-libs "-L${LOCALBASE}/lib -ltcl${TCL_VER:S/.//}"
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
