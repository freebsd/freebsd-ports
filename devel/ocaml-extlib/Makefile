# Ports collection makefile for:	extlib
# Date created:			Nov 2, 2004
# Whom:				mukai
#
# $FreeBSD$
#

PORTNAME=	extlib
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ocaml-lib
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	mukai@jmuk.org
COMMENT=	A complete - yet small - standard library for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

USE_GMAKE=	yes
USE_DOS2UNIX=	yes
ALL_TARGET=	all opt

.if !defined(NOPORTDOCS)
ALL_TARGET+=	doc
.endif

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/css/d' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
