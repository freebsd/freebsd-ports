# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	bz2
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/72/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	caml${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml library to manipulate bz2 files

DESTDIRNAME=	DONTUSEIT
GNU_CONFIGURE=	yes
USES=		gmake
USE_OCAML=		yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_WASH=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes

PORTDOCS=	*
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
