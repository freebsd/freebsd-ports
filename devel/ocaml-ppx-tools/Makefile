# Created by: Michael Grünewald <michipili@gmail.com>
# $FreeBSD$

PORTNAME=	ppx-tools
PORTVERSION=	0.99.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/alainfrisch/${PORTNAME:C/-/_/}/archive/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME:C/-/_/}_${PORTVERSION}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	michipili@gmail.com
COMMENT=	Tools for authors of ppx rewriters

LICENSE=	MIT

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
MAKE_JOBS_UNSAFE=yes
WRKSRC=		${WRKDIR}/${PORTNAME:C/-/_/}-${PORTNAME:C/-/_/}_${PORTVERSION}

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/ppx_tools/ppx_tools.cmxs

.include <bsd.port.mk>
