# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	xstrp4
PORTVERSION=	1.8.2
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml extension to expands brace expansions

LICENSE=	MIT

OPTIONS_DEFINE=	EXAMPLES

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAMLFIND_PLIST=	yes
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PORTEXAMPLES=	*
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} sample.* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
