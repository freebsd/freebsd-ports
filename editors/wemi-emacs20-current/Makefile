# New ports collection makefile for:	wemi-current for emacs20
# Version required:	1.12.x
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id$
#

DISTNAME=	wemi-${WEMI_VER}
CATEGORIES=	editors elisps
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/semi/wemi/

MAINTAINER?=	shige@kuis.kyoto-u.ac.jp

# distfile version
FLIM_VER=	1.12.1
WEMI_VER=	1.12.0
WEMIDOCDIR=	share/doc/semi

# emacs20
EMACS_NAME=	emacs
EMACS_PORT=	emacs20
EMACS_VER=	20.3
EMACS_LIBDIR=	share/${EMACS_NAME}

# target name for make build
ALL_TARGET?=	elc

PKGNAME=	wemi-${EMACS_PORT}-${WEMI_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		WEMIDOCDIR=${WEMIDOCDIR}
MAKE_FLAGS=	EMACS=${EMACS_CMD}

# depends on apel
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
# depends on flim
BUILD_DEPENDS+=	${PKG_DBDIR}/flim-${EMACS_PORT}-${FLIM_VER}:${PORTSDIR}/editors/flim-${EMACS_PORT}-current
RUN_DEPENDS+=	${PKG_DBDIR}/flim-${EMACS_PORT}-${FLIM_VER}:${PORTSDIR}/editors/flim-${EMACS_PORT}-current

# info files JIS to EUC
BUILD_DEPENDS+=	nkf:${PORTSDIR}/japanese/nkf

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300006
MAKEINFO=	makeinfo --no-split --force
.else
MAKEINFO=	makeinfo --no-split
.endif

post-build:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.texi mime-ui-ja.texi; do \
		mv $${i} $${i}.jis ; \
		cat $${i}.jis | nkf -e > $${i} ; \
		echo "===>   Please ignore the following errors." ; \
		${MAKEINFO} $${i} || ${TRUE} ; \
	done)

post-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/info ; \
		install-info ${PREFIX}/info/$${i} ${PREFIX}/info/dir ; \
	done)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${WEMIDOCDIR}
	@for i in ChangeLog NEWS README.* TODO VERSION ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${WEMIDOCDIR}/ ; \
	done
.endif

.include <bsd.port.post.mk>
