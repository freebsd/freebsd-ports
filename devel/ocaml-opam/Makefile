# Created by: J. Giovannangeli
# $FreeBSD$

PORTNAME=	opam
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://ocaml-extlib.googlecode.com/files/:extlib \
		https://github.com/ocaml/ocaml-re/archive/:ocamlre \
		http://erratique.ch/software/cmdliner/releases/:cmdliner \
		http://ocamlgraph.lri.fr/download/:ocamlgraph \
		https://gforge.inria.fr/frs/download.php/file/33593/:cudf \
		https://gforge.inria.fr/frs/download.php/file/33677/:dose \
		http://erratique.ch/software/uutf/releases/:uutf \
		http://erratique.ch/software/jsonm/releases/:jsonm \
		GHL:gh
PKGNAMEPREFIX=	ocaml-
DISTFILES=	${OPAM_EXT_DIST} \
		${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}.tar.gz:gh
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}.tar.gz

MAINTAINER=	joris@giovannangeli.fr
COMMENT=	Source-based package manager for OCaml

LICENSE=	GPLv3

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
GH_PROJECT=	opam
GH_TAGNAME=	1.2.0
GH_COMMIT=	cbe460b

USES=		gmake
USE_OCAML=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	TERM=xterm
ALL_TARGET=	lib-ext all man

OPAM_EXT_DIST=	extlib-1.5.3.tar.gz:extlib \
		ocaml-re-1.2.0.tar.gz:ocamlre \
		cmdliner-0.9.4.tbz:cmdliner \
		ocamlgraph-1.8.5.tar.gz:ocamlgraph \
		cudf-0.7.tar.gz:cudf \
		dose3-3.2.2.tar.gz:dose \
		uutf-0.9.3.tbz:uutf \
		jsonm-0.9.1.tbz:jsonm \

OPTIONS_DEFINE=		RSYNC GIT WGET HG DARCS ASPCUD
OPTIONS_DEFAULT=	RSYNC GIT WGET

RSYNC_DESC=		"Support remote repository synchronized with Rsync"
WGET_DESC=		"Support remote repository synchronized with git"
GIT_DESC=		"Support remote repository synchronized with HTTP"
HG_DESC=		"Support remote repository synchronized with mercurial"
DARCS_DESC=		"Support remote repository synchronized with darcs"
ASPCUD_DESC=		"Use aspcud as an external dependencies solver"

WGET_RUN_DEPENDS:=	wget:${PORTSDIR}/ftp/wget
RSYNC_RUN_DEPENDS:=	rsync:${PORTSDIR}/net/rsync
GIT_RUN_DEPENDS:=	git:${PORTSDIR}/devel/git
HG_RUN_DEPENDS:=	hg:${PORTSDIR}/devel/mercurial
DARCS_RUN_DEPENDS:=	darcs:${PORTSDIR}/devel/hs-darcs
ASPCUD_RUN_DEPENDS:=	aspcud:${PORTSDIR}/math/aspcud

MAKE_JOBS_UNSAFE=	yes

post-extract:
	${INSTALL} ${OPAM_EXT_DIST:C/:.*$//:S/^/${DISTDIR}\//} \
		${WRKSRC}/src_ext/

.include <bsd.port.mk>
