# Created by: J. Giovannangeli
# $FreeBSD$

PORTNAME=	opam
PORTVERSION=	2.0.6
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

ALL_TARGET=	lib-ext all

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-checks

OPTIONS_DEFINE=		RSYNC GIT HG DARCS
OPTIONS_DEFAULT=	RSYNC GIT

RSYNC_DESC=		Remote repository synchronized with Rsync
GIT_DESC=		Remote repository synchronized with git
HG_DESC=		Remote repository synchronized with mercurial
DARCS_DESC=		Remote repository synchronized with darcs

RSYNC_RUN_DEPENDS=	rsync:net/rsync
GIT_RUN_DEPENDS=	git:devel/git
HG_RUN_DEPENDS=		hg:devel/mercurial
DARCS_RUN_DEPENDS=	darcs:devel/hs-darcs

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
