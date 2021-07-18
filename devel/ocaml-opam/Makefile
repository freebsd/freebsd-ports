# Created by: J. Giovannangeli

PORTNAME=	opam
PORTVERSION=	2.0.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocaml/opam/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	opam-full-${DISTVERSION}

MAINTAINER=	hannes@mehnert.org
COMMENT=	Source-based package manager for OCaml

LICENSE=	LGPL21

RUN_DEPENDS=	curl:ftp/curl \
		gpatch:devel/patch

USES=		gmake
USE_OCAML=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-checks

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	lib-ext all

OPTIONS_DEFINE=		DARCS GIT MERCURIAL RSYNC
OPTIONS_DEFAULT=	GIT RSYNC
NO_OPTIONS_SORT=	yes

RSYNC_DESC=		Remote repository synchronized with Rsync

DARCS_RUN_DEPENDS=	darcs:devel/hs-darcs
GIT_RUN_DEPENDS=	git:devel/git
MERCURIAL_RUN_DEPENDS=	${PY_MERCURIAL}
RSYNC_RUN_DEPENDS=	rsync:net/rsync

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opam-installer

.include <bsd.port.mk>
