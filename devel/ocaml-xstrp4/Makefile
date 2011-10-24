# New ports collection makefile for:	ocaml-xstrp4
# Date created:		2006-08-01
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	xstrp4
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OCaml extension to expands brace expansions

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}

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
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.* ${EXAMPLESDIR}

	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}

	@${ECHO_CMD} "@dirrm share/examples/ocaml/${PORTNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/examples/ocaml 2>/dev/null ||true"\
  		>> ${TMPPLIST}

.include <bsd.port.post.mk>
