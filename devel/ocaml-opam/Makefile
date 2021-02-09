# Created by: J. Giovannangeli
# $FreeBSD$

PORTNAME=	opam
PORTVERSION=	2.0.8
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

OPTIONS_DEFINE=		RSYNC GIT HG DARCS
OPTIONS_DEFAULT=	RSYNC GIT
NO_OPTIONS_SORT=	yes

DARCS_DESC=		Remote repository synchronized with darcs
GIT_DESC=		Remote repository synchronized with git
HG_DESC=		Remote repository synchronized with mercurial
RSYNC_DESC=		Remote repository synchronized with Rsync

DARCS_RUN_DEPENDS=	darcs:devel/hs-darcs
GIT_RUN_DEPENDS=	git:devel/git
HG_RUN_DEPENDS=		${PY_MERCURIAL}
RSYNC_RUN_DEPENDS=	rsync:net/rsync

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opam-installer

.include <bsd.port.mk>
