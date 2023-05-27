PORTNAME=	opam
DISTVERSION=	2.1.5
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocaml/opam/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	opam-full-${DISTVERSION}

MAINTAINER=	hannes@mehnert.org
COMMENT=	Source-based package manager for OCaml
WWW=		https://opam.ocaml.org/

LICENSE=	LGPL21

BROKEN_armv6=	ld: error: can't create dynamic relocation R_ARM_ABS32 against symbol: caml_program in readonly segment
BROKEN_armv7=	ld: error: can't create dynamic relocation R_ARM_ABS32 against symbol: caml_program in readonly segment

RUN_DEPENDS=	curl:ftp/curl \
		gpatch:devel/patch

USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-checks

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	cold-lib-ext cold-all

OPTIONS_DEFINE=		DARCS GIT MERCURIAL RSYNC
OPTIONS_DEFAULT=	GIT RSYNC
NO_OPTIONS_SORT=	yes

RSYNC_DESC=		Remote repository synchronized with Rsync

DARCS_RUN_DEPENDS=	darcs:devel/hs-darcs
GIT_RUN_DEPENDS=	git:devel/git
MERCURIAL_RUN_DEPENDS=	${PY_MERCURIAL}
RSYNC_RUN_DEPENDS=	rsync:net/rsync

NOPRECIOUSMAKEVARS=	yes

pre-configure:
	cd ${WRKSRC} && ${MAKE_CMD} compiler

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opam-installer
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opam

.include <bsd.port.mk>
