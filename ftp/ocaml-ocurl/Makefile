# Ports collection makefile for:	ocurl
# Date created:			Aug 6, 2004
# Whom:				Marwan BURELLE <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	ocurl
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	SF
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interface for OCaml to the curl lib

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

WRKSRC=		${WRKDIR}/ocurl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-findlib"

PKGDEINSTALL=	${PKGINSTALL}
FINDLIB_PKGNAME=${PORTNAME:S/o//}

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/${FINDLIB_PKGNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/${FINDLIB_PKGNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove ${FINDLIB_PKGNAME} 2>/dev/null || true" >> ${TMPPLIST}
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
