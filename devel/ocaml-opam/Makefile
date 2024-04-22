PORTNAME=	opam
DISTVERSION=	2.1.5
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocaml/opam/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	opam-full-${DISTVERSION}

MAINTAINER=	hannes@mehnert.org
COMMENT=	Source-based package manager for OCaml
WWW=		https://opam.ocaml.org/

LICENSE=	LGPL21

RUN_DEPENDS=	curl:ftp/curl \
		gpatch:devel/patch \
		gmake:devel/gmake \
		${RUN_DEPENDS_${ARCH}}
RUN_DEPENDS_armv6=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS_armv7=	${LOCALBASE}/bin/as:devel/binutils

USES=		gmake
ARCH!=		uname -p
.if ${ARCH} == armv6 || ${ARCH} == armv7
USE_BINUTILS=	yes
.endif

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-checks

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	cold-lib-ext cold-all

LDFLAGS_armv6=	-Wl,-z,notext
LDFLAGS_armv7=	-Wl,-z,notext
LDFLAGS_powerpc=	-Wl,-z,notext
LDFLAGS+=	${LDFLAGS_${ARCH}}

NOPRECIOUSMAKEVARS=	yes

OPTIONS_DEFINE=		DARCS GIT MERCURIAL RSYNC
OPTIONS_DEFAULT=	GIT RSYNC
NO_OPTIONS_SORT=	yes

RSYNC_DESC=		Remote repository synchronized with Rsync

DARCS_RUN_DEPENDS=	darcs:devel/hs-darcs
GIT_RUN_DEPENDS=	git:devel/git
MERCURIAL_RUN_DEPENDS=	${PY_MERCURIAL}
RSYNC_RUN_DEPENDS=	rsync:net/rsync

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} compiler)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opam-installer
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/opam

.include <bsd.port.mk>
