# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	camomile
PORTVERSION=	0.8.3
CATEGORIES=	devel
MASTER_SITES=	SF
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive Unicode library for Objective Caml

LICENSE=	LGPL21

USES=		gmake tar:bzip2
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_LDCONFIG=yes
USE_OCAML_WASH=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}

post-install:
	@${FIND} ${STAGEDIR}${DATADIR} ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${OCAMLFIND_DESTDIR}/${PORTNAME} ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${OCAMLFIND_DESTDIR}/${PORTNAME} -type d | \
		${SORT} -r | ${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' \
			>> ${TMPPLIST}

.include <bsd.port.mk>
