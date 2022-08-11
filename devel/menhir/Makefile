PORTNAME=	menhir
PORTVERSION=	20170712
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~fpottier/menhir/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LR(1) parser generator for OCaml

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

USES=		gmake shebangfix
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
OCAML_PKGDIRS=		menhirLib

SHEBANG_FILES=	demos/find-menhir.sh
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man| ; \
		 s|doc/menhir|doc/ocaml/menhir| ; \
		 s| \($$(bindir)\)| $${DESTDIR}\1| ; \
		 s| \($$(libdir)\)| $${DESTDIR}\1| ; \
		 s| \($$(docdir)\)| $${DESTDIR}\1| ; \
		 s| \($$(mandir)\)| $${DESTDIR}\1|' ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/menhir

.include <bsd.port.mk>
