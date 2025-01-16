PORTNAME=	sem
PORTVERSION=	0.0.2
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://ocaml-sem.sourceforge.net/files/ \
		SF/ocaml-${PORTNAME}/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POSIX semaphores for OCaml
WWW=		https://ocaml-sem.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ocaml:findlib,ldconfig tar:bzip2

MAKE_ENV=	OCAML_LIB_INSTALL="${PREFIX}/lib/ocaml/site-lib/sem" \
		INCDIRS="${LOCALBASE}/include" LIBDIRS="${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	all
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(WITH_CUSTOM)
MAKE_ENV+=	NO_CUSTOM=y
.endif

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
