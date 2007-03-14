# New ports collection makefile for:	lacaml
# Date created:		2006-08-15
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	lacaml
PORTVERSION=	3.0.20
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml.info/ocaml_sources/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	OCaml interface to BLAS and LAPACK libraries

LIB_DEPENDS=	blas.2:${PORTSDIR}/math/blas \
		lapack.4:${PORTSDIR}/math/lapack

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_LDCONFIG=yes
USE_OCAML_WASH=	yes

CFLAGS+=	-fPIC
MAKE_ENV+=	OCAMLMKLIB_FLAGS="-L${LOCALBASE}/lib"

DOCS=		README TODO
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
#
# CFLAGS safety
#
	@${REINPLACE_CMD} -E \
		-e 's,^(CFLAGS[[:space:]]*:=[[:space:]]*).*,\1${CFLAGS},' \
		${WRKSRC}/lib/Makefile

# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
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
