PORTNAME=	dbm
PORTVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/728/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	caml${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml binding to the NDBM and GDBM database library

LICENSE=	LGPL20

CONFLICTS=	ocaml-[0-3]* ocaml-nox11-[0-3]*

USES=		tar:tgz
HAS_CONFIGURE=	yes
USE_OCAML=	yes
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
MAKE_ENV+=	DESTDIR="${STAGEDIR}"

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/dbm \
		${STAGEDIR}${PREFIX}/lib/ocaml/stublibs

post-install:
	${INSTALL_DATA} ${WRKSRC}/META \
		${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/dbm

.include <bsd.port.mk>
