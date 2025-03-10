PORTNAME=	xstrp4
PORTVERSION=	1.8.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml extension to expands brace expansions
WWW=		https://www.ocaml-programming.de/packages/

LICENSE=	MIT

OPTIONS_DEFINE=	EXAMPLES

USES=		gmake ocaml:camlp4,findplist

HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PORTEXAMPLES=	*
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} sample.* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
