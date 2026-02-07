PORTNAME=	opam
DISTVERSION=	2.4.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocaml/opam/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	opam-full-${DISTVERSION}

MAINTAINER=	hannes@mehnert.org
COMMENT=	Source-based package manager for OCaml
WWW=		https://opam.ocaml.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	curl:ftp/curl \
		gmake:devel/gmake

USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mccs --with-vendored-deps

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	cold-all

NOPRECIOUSMAKEVARS=	yes

OPTIONS_DEFINE=		DARCS GIT MERCURIAL RSYNC
OPTIONS_DEFAULT=	GIT RSYNC
NO_OPTIONS_SORT=	yes

RSYNC_DESC=	Remote repository synchronized with Rsync

DARCS_RUN_DEPENDS=	darcs:devel/hs-darcs
GIT_RUN_DEPENDS=	git:devel/git
MERCURIAL_RUN_DEPENDS=	${PY_MERCURIAL}
RSYNC_RUN_DEPENDS=	rsync:net/rsync

.include <bsd.port.pre.mk>
.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386 || \
	${ARCH} == powerpc
LDFLAGS+=	-Wl,-z,notext
.endif
.if ${ARCH} == armv6 || ${ARCH} == armv7
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
USE_BINUTILS=	yes
.endif
.if ${ARCH} == powerpc
LLD_UNSAFE=	yes
.endif

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} compiler)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opam-installer
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opam

.include <bsd.port.post.mk>
