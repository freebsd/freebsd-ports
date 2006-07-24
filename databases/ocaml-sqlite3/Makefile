# Ports collection makefile for: ocaml-sqlite3
# Date created: 27th February 2006
# Whom: "Meikel Brandmeyer" <ocaml-sqlite3-port@kotka.de>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	0.2.0
CATEGORIES=	databases
MASTER_SITES=	http://metamatix.org/~ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ocaml-sqlite3-port@kotka.de
COMMENT=	OCaml bindings to sqlite3 library

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

WRKSRC=		${WRKDIR}/ocaml-sqlite3

USE_GCC=	3.2+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}"\
		CFLAGS="${CFLAGS}"\
		CPPFLAGS="-UHAVE_ALLOCA_H -I${PREFIX}/include"\
		LDFLAGS="-L${PREFIX}/lib"

USE_BZIP2=	yes

SUB_FILES=	pkg-install pkg-deinstall

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	README style.css *.html

do-install:
	@${ECHO_MSG} "==>  Installing port files for ${PKGORIGIN}..."
	@( cd ${WRKSRC};\
	   OCAMLFIND_DESTDIR="${PREFIX}/lib/ocaml/site-lib"\
	   OCAMLFIND_LDCONF="${PREFIX}/lib/ocaml/ld.conf"\
	   ocamlfind install\
		sqlite3 META sqlite3.cmi sqlite3.mli sqlite3.cma\
		*.cmxa *.a *.cmx *.so;\
	   OCAMLPATH="${PREFIX}/lib/ocaml/site-lib"\
	   ocamlfind ocamlmktop -o sqlite3top -package "sqlite3" sqlite3.cma;\
	   ${INSTALL_SCRIPT} sqlite3top ${PREFIX}/bin/ocamlsqlite3 )
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "==>  Installing port documentation for ${PKGORIGIN}..."
	@${MKDIR} ${DOCSDIR}
	@( cd ${WRKSRC}; ${INSTALL_DATA} README ${DOCSDIR} )
	@( cd ${WRKSRC}/doc;\
	   for f in `${FIND} . -type f -print`; do\
		${INSTALL_DATA} $${f} ${DOCSDIR};\
	   done )
.endif

.include <bsd.port.mk>
