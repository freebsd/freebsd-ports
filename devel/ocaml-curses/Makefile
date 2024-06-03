PORTNAME=	curses
PORTVERSION=	1.0.11
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	(N)curses binding for OCaml
WWW=		https://github.com/mbacarella/curses

LICENSE=	LGPL21+ # with a special exception to clause 6
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses ocaml:dune pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	mbacarella
USE_OCAML=		yes
USE_OCAML_LDCONFIG=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n(version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/curses/dllcurses_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/curses/curses.cmxs

.include <bsd.port.mk>
