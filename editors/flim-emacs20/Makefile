# New ports collection makefile for:	flim for emacs20
# Version required:	1.9.2
# Date created:		23 September 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id$
#

DISTNAME=	flim-${FLIM_VER}
PKGNAME=	flim-${EMACS_PORT}-${FLIM_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/flim/flim-stable/

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT} \
		nkf:${PORTSDIR}/japanese/nkf \
		${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT} \
		${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}

ALL_TARGET?=	elc
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		FLIMDOCDIR=${FLIMDOCDIR}
MAKE_FLAGS=	EMACS=${EMACS_CMD}

# distfile version
FLIM_VER=	1.9.2
FLIMDOCDIR=	share/doc/flim

# emacs20
EMACS_NAME=	emacs
EMACS_PORT=	emacs20
EMACS_VER=	20.3
EMACS_LIBDIR=	share/${EMACS_NAME}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}

post-build:
	@(cd ${WRKSRC} ; \
	for i in mime-en.texi mime-ja.texi; do \
		${MV} $${i} $${i}.jis ; \
		${CAT} $${i}.jis | nkf -e > $${i} ; \
		${ECHO} "===>   Please ignore the following errors." ; \
		makeinfo --no-split $${i} || ${TRUE} ; \
	done)

post-install:
	@(cd ${WRKSRC} ; \
	for i in mime-en.info mime-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/info ; \
		install-info ${PREFIX}/info/$${i} ${PREFIX}/info/dir ; \
	done)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${FLIMDOCDIR}
	@for i in ChangeLog README.* ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${FLIMDOCDIR}/ ; \
	done
.endif

.include <bsd.port.mk>
