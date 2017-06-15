# Created by: J. Giovannangeli
# $FreeBSD$

PORTNAME=	opam
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocaml/opam/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	opam-full-${DISTVERSION}
DIST_SUBDIR=	opam-01

MAINTAINER=	joris@giovannangeli.fr
COMMENT=	Source-based package manager for OCaml

LICENSE=	GPLv3

RUN_DEPENDS=		camlp4:devel/ocaml-camlp4

USES=		gmake
USE_OCAML=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	TERM=xterm
ALL_TARGET=	lib-ext all man

OPTIONS_DEFINE=		RSYNC GIT WGET HG DARCS ASPCUD
OPTIONS_DEFAULT=	RSYNC GIT WGET ASPCUD

RSYNC_DESC=		Remote repository synchronized with Rsync
WGET_DESC=		Remote repository synchronized with git
GIT_DESC=		Remote repository synchronized with HTTP
HG_DESC=		Remote repository synchronized with mercurial
DARCS_DESC=		Remote repository synchronized with darcs
ASPCUD_DESC=		Use aspcud as an external dependencies solver

WGET_RUN_DEPENDS=	wget:ftp/wget
RSYNC_RUN_DEPENDS=	rsync:net/rsync
GIT_RUN_DEPENDS=	git:devel/git
HG_RUN_DEPENDS=		hg:devel/mercurial
DARCS_RUN_DEPENDS=	darcs:devel/hs-darcs
ASPCUD_RUN_DEPENDS=	aspcud:math/aspcud

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
