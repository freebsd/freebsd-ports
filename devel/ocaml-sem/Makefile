# New ports collection makefile for:	ocaml-sem
# Date created:		19 April 2005
# Whom:			asmith
#
# $FreeBSD$
#

PORTNAME=	sem
PORTVERSION=	0.0.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rtelekom.ru/pub/FreeBSD/ports/distfiles/ \
		http://ocaml-sem.sourceforge.net/files/ \
		${MASTER_SITE_FREEBSD_ORG}ports/distfiles/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	argentoff@gmail.com
COMMENT=	POSIX semaphores for OCaml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

MAKE_ENV=	OCAML_LIB_INSTALL="${PREFIX}/lib/ocaml/site-lib/sem" \
		INCDIRS="${LOCALBASE}/include" LIBDIRS="${LOCALBASE}/lib"

.if !defined(WITH_CUSTOM)
MAKE_ENV+=	NO_CUSTOM=y
.endif
ALL_TARGET=	all

PORTDOCS=	html README
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

USE_BZIP2=	yes
USE_GMAKE=	yes

PKGDEINSTALL=	${PKGINSTALL}

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/sem -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/sem" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove sem 2>/dev/null || true" >> ${TMPPLIST}
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	${CP} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
