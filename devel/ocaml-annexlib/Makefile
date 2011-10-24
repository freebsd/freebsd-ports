# New ports collection makefile for:	ocaml-annexlib
# Date created:		2006-08-01
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	annexlib
PORTVERSION=	0.13.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://raevnos.pennmush.org/code/extlib/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml subroutines collection

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre
RUN_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_LDCONFIG=yes

GNU_CONFIGURE=	yes

ALL_TARGET=	all opt
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

post-install:
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
