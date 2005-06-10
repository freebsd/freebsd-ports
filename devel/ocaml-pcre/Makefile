# New ports collection makefile for:   ocaml-pcre
# Date created:        21 April 2002
# Whom:                Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	pcre
PORTVERSION=	5.10.0
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml.info/ocaml_sources/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	pcre-ocaml-${PORTVERSION}

MAINTAINER=	marwan.burelle@lri.fr
COMMENT=	Perl compatible regular expressions for Objective Caml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre-utf8

USE_GMAKE=	yes
MAKE_ENV=	OCAML_LIB_INSTALL="${PREFIX}/lib/ocaml/site-lib/pcre" \
		INCDIRS="${LOCALBASE}/include" LIBDIRS="${LOCALBASE}/lib" \
		OCAMLFIND_DESTDIR="${PREFIX}/lib/ocaml/site-lib"
.if !defined(WITH_CUSTOM)
MAKE_ENV+=	NO_CUSTOM=y
.endif
ALL_TARGET=	all

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
USE_GHOSTSCRIPT_BUILD=	yes
ALL_TARGET+=	doc
PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

PKGDEINSTALL=	${PKGINSTALL}

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/pcre -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/pcre" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove pcre 2>/dev/null || true" >> ${TMPPLIST}
.if defined(WITH_DOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
