# New ports collection makefile for:	pomap
# Date created:		2006-08-15
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	pomap
PORTVERSION=	2.9.8
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml.info/ocaml_sources/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	OCaml library to maintain a list of partially ordered elements

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_WASH=	yes

DOCS=		README
DOCSDIR=	${TARGETDIR}/share/doc/ocaml/${PORTNAME}
EXAMPLESDIR=	${TARGETDIR}/share/examples/ocaml/${PORTNAME}

# XXX: exists untill it will be committed to bsd.port.mk
COPYTREE_SHARE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
		2>&1) && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$1 && \
		${FIND} $$1/ -type d -exec ${CHMOD} 755 {} \; && \
		${FIND} $$1/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;' --

.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif

post-install:
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${TARGETDIR}/,," >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
	@${FIND} ${EXAMPLESDIR}/ ! -type d | \
		${SED} 's,^${TARGETDIR}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR}/ -type d | ${SORT} -r | \
		${SED} 's,^${TARGETDIR}/,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR}/ ! -type d | \
		${SED} 's,^${TARGETDIR}/,,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR}/ -type d | ${SORT} -r | \
		${SED} 's,^${TARGETDIR}/,@dirrm ,' >> ${TMPPLIST}
# XXX: temporary workaround for non-standard PREFIX
	@${ECHO_CMD} "@unexec rmdir %D/share/doc/ocaml 2>/dev/null || true" \
		>> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/examples/ocaml 2>/dev/null||true" \
		>> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
