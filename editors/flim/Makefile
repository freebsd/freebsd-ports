# New ports collection makefile for:	flim for emacs
# Version required:	1.12.5
# Date created:		9 May 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1999/05/10 13:31:16 shige Exp $
#

DISTNAME=	flim-${FLIM_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/flim/flim-1.12/

MAINTAINER?=	shige@FreeBSD.ORG

PORTCLASS?=	master

# distfile version
FLIM_VER=	1.12.5
FLIMDOCDIR=	share/doc/flim
FLIM_SETUPEL=	flim-setup.el

.if (${PORTCLASS} == "master")
# for emacs
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=	share/${EMACS_NAME}
REQUIRE_SETUPEL=  YES
.endif

# target name for make build
ALL_TARGET?=	elc

# if RUN_DEPENDS-emacs port name has the suffix '-common'.
.if !defined(HAVE_COMMON_PORT)
HAVE_COMMON_PORT=	NO
.endif
# if RUN_DEPENDS-emacs needs setup elisp
.if !defined(REQUIRE_SETUPEL)
REQUIRE_SETUPEL=	NO
.endif

.if defined(EMACS_PORT)
PKGNAME=	flim-${EMACS_PORT}-${FLIM_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAVE_COMMON_PORT) && (${HAVE_COMMON_PORT} == "YES")
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		FLIMDOCDIR=${FLIMDOCDIR}
MAKE_FLAGS=	EMACS=${EMACS_CMD}
.if (${EMACS_VER} == "19.34")
# depends on custom: emacs-19.34 or mule-19.34
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/custom.el:${PORTSDIR}/editors/custom-${EMACS_PORT}
.endif
# depends on apel
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT}
# depends on mmencode
.if (${EMACS_NAME} != "xemacs")
RUN_DEPENDS+=	mmencode:${PORTSDIR}/mail/metamail
.endif
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR."
	@${FALSE}
.endif

# info files JIS to EUC
BUILD_DEPENDS+=	nkf:${PORTSDIR}/japanese/nkf

.if (${REQUIRE_SETUPEL} == "YES")
pre-configure:
	@${CP} ${FILESDIR}/${FLIM_SETUPEL}.in ${WRKDIR}
.endif

.include <bsd.port.pre.mk>

MAKEINFO=	makeinfo --no-split --no-validate

post-build:
	@(cd ${WRKSRC} ; \
	for i in mime-en.texi mime-ja.texi; do \
		${MV} $${i} $${i}.jis ; \
		${CAT} $${i}.jis | nkf -e > $${i} ; \
		${ECHO_MSG} "===>   Please ignore the following errors." ; \
		${MAKEINFO} $${i} || ${TRUE} ; \
	done)

post-install:
	@(cd ${WRKSRC} ; \
	for i in mime-en.info mime-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/info ; \
		install-info ${PREFIX}/info/$${i} ${PREFIX}/info/dir ; \
	done)
.if (${REQUIRE_SETUPEL} == "YES")
	@${INSTALL_DATA} ${WRKDIR}/${FLIM_SETUPEL} \
			${PREFIX}/${EMACS_LIBDIR}/site-lisp
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${FLIMDOCDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog README.* NEWS VERSION ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${FLIMDOCDIR}/ ; \
	done)
.endif

.include <bsd.port.post.mk>
