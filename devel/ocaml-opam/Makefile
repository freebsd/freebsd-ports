# Created by: J. Giovannangeli
# $FreeBSD$

PORTNAME=	opam
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.ocamlpro.com/pub/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	opam-full-${PORTVERSION}

MAINTAINER=	joris.gio@gmail.com
COMMENT=	Source-based package manager for OCaml

LICENSE=	GPLv3

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_OCAML=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/opam bin/opam-mk-repo

MAN1=	opam-check.1 \
	opam-remote.1 \
	opam-config.1 \
	opam-remove.1 \
	opam-help.1 \
	opam-repository.1 \
	opam-info.1 \
	opam-search.1 \
	opam-init.1 \
	opam-switch.1 \
	opam-install.1 \
	opam-update.1 \
	opam-list.1 \
	opam-upgrade.1 \
	opam-mk-repo.1 \
	opam-upload.1 \
	opam-pin.1 \
	opam.1 \
	opam-reinstall.1

.include <bsd.port.mk>
