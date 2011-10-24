# New ports collection makefile for:	res
# Date created:		2006-08-15
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	res
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://hg.ocaml.info/release/res/archive/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	release-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically Resizing Contiguous Memory for OCaml

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_WASH=	yes
MAKE_JOBS_UNSAFE=	yes

DOCS=		README.txt
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-release-${PORTVERSION}

.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif

post-install:
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
	@${FIND} ${EXAMPLESDIR}/ ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR}/ -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR}/ ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR}/ -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
# XXX: temporary workaround for non-standard PREFIX
	@${ECHO_CMD} "@unexec rmdir %D/share/doc/ocaml 2>/dev/null || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/examples/ocaml 2>/dev/null||true" \
		>> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
