# Created by: asmith
# $FreeBSD$

PORTNAME=	sem
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://ocaml-sem.sourceforge.net/files/ \
		SF/ocaml-${PORTNAME}/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POSIX semaphores for OCaml

USES=		gmake tar:bzip2
USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_FINDLIB=	yes
MAKE_ENV=	OCAML_LIB_INSTALL="${PREFIX}/lib/ocaml/site-lib/sem" \
		INCDIRS="${LOCALBASE}/include" LIBDIRS="${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	all
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
OPTIONS_DEFINE=	DOCS

.if !defined(WITH_CUSTOM)
MAKE_ENV+=	NO_CUSTOM=y
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
