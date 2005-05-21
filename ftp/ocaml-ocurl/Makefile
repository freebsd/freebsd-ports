# Ports collection makefile for:	ocurl
# Date created:			Aug 6, 2004
# Whom:				Marwan BURELLE <marwan.burelle@lri.fr>
# $FreeBSD$

PORTNAME=	ocurl
PORTVERSION=	0.2.0
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tgz

MAINTAINER=	marwan.burelle@lri.fr
COMMENT=	An interface for OCaml to the curl lib

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
RUN_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

BROKEN=		Changes permissions of installed file

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-findlib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PKGDEINSTALL=	${PKGINSTALL}
FINDLIB_PKGNAME=${PORTNAME:S/o//}

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/${FINDLIB_PKGNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/${FINDLIB_PKGNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove ${FINDLIB_PKGNAME} 2>/dev/null || true" >> ${TMPPLIST}
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
