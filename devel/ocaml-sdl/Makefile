# ex:ts=8
# Ports collection makefile for:	ocaml-sdl
# Date created:			Jun 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	0.6.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ocamlsdl
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocamlsdl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OCaml interface to the SDL

BROKEN=		Does not build

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		lablgl:${PORTSDIR}/graphics/ocaml-lablgl

USE_BZIP2=	yes
USE_SDL=	sdl ttf image mixer
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/sdl ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/sdl" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/ocaml/stublibs -name "dllsdl*.so" | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/html/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
