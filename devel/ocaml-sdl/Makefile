# ex:ts=8
# Ports collection makefile for:	ocaml-sdl
# Date created:			Jun 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	0.7.2
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	SF/ocaml${PORTNAME}/OCamlSDL/ocaml${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocamlsdl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OCaml interface to the SDL

BUILD_DEPENDS=	lablgl:${PORTSDIR}/graphics/ocaml-lablgl

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_LDCONFIG=yes
USE_SDL=	sdl ttf image mixer
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-findlib

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/{PORTNAME}

PORTDOCS=	*

.if !defined(NOPORTDOCS)
INFO=	ocamlsdl
.endif

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ocamlsdl.info ${PREFIX}/${INFO_PATH}
.endif

.include <bsd.port.post.mk>
