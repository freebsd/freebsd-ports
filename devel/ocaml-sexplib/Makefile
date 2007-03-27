# New ports collection makefile for:	ocaml-sexplib
# Date created:		2006-08-01
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	sexplib
PORTVERSION=	2.2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.janestcapital.com/ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An OCaml library for working with S-expressions

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif
	@${REINPLACE_CMD} -E -e "/lib_test/d" ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}

	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/doc/ocaml/${PORTNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/doc/ocaml 2>/dev/null ||true"\
		>> ${TMPPLIST}

.include <bsd.port.post.mk>
