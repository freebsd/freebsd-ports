# for committer: bump PORTREVISION for math/facile whenever ocaml gets updated

PORTNAME=	ocaml
PORTVERSION=	4.14.2
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/pub/distrib/${DISTNAME:R}/ \
		http://caml.inria.fr/pub/distrib/${DISTNAME:R}/:docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${_DISTFILES:M*.tar.*}
PKGNAMESUFFIX=	${SFX}

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Objective Caml compiler and programming environment
WWW=		https://ocaml.org/

LICENSE=	LGPL21

BROKEN_riscv64=	fails to build: hasgot.c:3:12: use of undeclared identifier 'secure_getenv'

RUN_DEPENDS=	${RUN_DEPENDS_${ARCH}}
RUN_DEPENDS_armv7=	${LOCALBASE}/bin/as:devel/binutils

USES=		compiler:c11 cpe gmake tar:xz
ARCH!=		uname -p
.if ${ARCH} == armv6 || ${ARCH} == armv7
USE_BINUTILS=	yes
.endif
CPE_VENDOR=	inria
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-force-safe-string \
		--enable-ocamltest
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

ALL_TARGET=	world.opt
TEST_TARGET=	tests
LDFLAGS_armv7=	-Wl,-z,notext
LDFLAGS_i386=	-Wl,-z,notext
LDFLAGS_powerpc=	-Wl,-z,notext
PIE_UNSAFE=	yes
SSP_UNSAFE=	yes

CONFLICTS=	metaocaml ocaml-nox11
STRIP=

PORTDOCS=	${DISTNAME:R}-refman.pdf htmlman

OPTIONS_DEFINE=		DOCS EXAMPLES MANPAGES THREADS
OPTIONS_DEFAULT=	MANPAGES THREADS

OPTIONS_SUB=	yes

DOCS_DISTFILES=			${DISTNAME:R}-refman-html.tar.gz:docs \
				${DISTNAME:R}-refman.pdf:docs
THREADS_CONFIGURE_ENABLE=	systhreads

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LLD_UNSAFE=	yes
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR} && ${COPYTREE_SHARE} htmlman ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME:R}-refman.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
