# Ports collection makefile for: ocaml-sqlite3
# Date created: 27th February 2006
# Whom: "Meikel Brandmeyer" <ocaml-sqlite3-port@kotka.de>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	1.6.1
CATEGORIES=	databases
MASTER_SITES=	http://hg.ocaml.info/release/${PKGNAMEPREFIX}${PORTNAME}/archive/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	release-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml bindings to sqlite3 library

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-release-${PORTVERSION}

USE_AUTOTOOLS=		autoconf
USE_GMAKE=		yes
USE_SQLITE=		yes
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}"\
		CFLAGS="${CFLAGS}"\
		CPPFLAGS="-UHAVE_ALLOCA_H -I${PREFIX}/include"\
		LDFLAGS="-L${PREFIX}/lib"\
		LIBS="${PTHREAD_LIBS}"

USE_BZIP2=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	style.css *.html

PLIST_FILES=	bin/sqlite3top

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@( cd ${WRKSRC}/doc;\
	   for f in `${FIND} . -type f -print`; do\
		${INSTALL_DATA} $${f} ${DOCSDIR};\
	   done )
.endif

.include <bsd.port.mk>
