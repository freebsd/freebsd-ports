# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	xstrp4
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OCaml extension to expands brace expansions

LICENSE=	MIT

OPTIONS_DEFINE=	EXAMPLES

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes

HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_DIRSTRY+=	${OCAML_EXAMPLESDIR:S,^${PREFIX}/,,}
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} sample.* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
