# New ports collection makefile for:	skk10-elisp-emacs20
# Date created:		21 September 1999
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skk-elisp
PORTVERSION=	${SKK10_VER}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/skk/
DISTNAME=	skk${SKK10_VER}

MAINTAINER?=	shige@FreeBSD.org

SKK10_VER=	10.59

# This port is a master port.
PORT_CLASS?=	master

.if (${PORT_CLASS} == "master")
# emacsen-port-name
EMACS_PORT_NAME=	emacs20
.endif

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
# dependency: apel
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-${EMACS_PORT_NAME}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif

WRKSRC=		${WRKDIR}/skk-${SKK10_VER}
ALL_TARGET?=	elc
MAKE_ARGS=	EMACS=${EMACS_CMD}
PLIST_SUB=	EMACS=${EMACS_CMD} EMACS_LIBDIR=${EMACS_LIBDIR} \
		SKK_JISYODIR=${SKKJISYODIR} SKK_DOCDIR=${SKK_DOCDIR} \
		SKK_STARTUPEL=${SKK_STARTUPEL}

# information of skk-jisyo
WITH_SKKJISYO?=	YES
SKKJISYODIR=	share/skk
SKK_DOCDIR=	share/doc/skk10
SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${PORTSDIR}/japanese/skk-jisyo
SKK_STARTUPEL=	skk-startup.el

.if (${WITH_SKKJISYO} == "YES")
# dependency: skk-jisyo
RUN_DEPENDS+=	${LOCALBASE}/${SKKJISYODIR}/${SKKJISYO}:${SKK_MASTERDIR}
.endif

EXPERIMENTAL_LISPS=	experimental/skk-abbrev.el \
			experimental/dbm/skk-dbm.el \
			experimental/skk-dcomp.el \
			experimental/skk-hankaku-mode.el \
			experimental/skk-jisx0201.el \
			experimental/skk-lookup.el \
			experimental/tut-code/skk-def.el \
			experimental/tut-code/skk-tutcdef.el \
			experimental/tut-code/skk-tutcode.el

pre-fetch:
.if (${WITH_SKKJISYO} == "YES")
	@${ECHO_MSG} "NOTE: You can avoid installing SKK-JISYO by adding"
	@${ECHO_MSG} "    WITH_SKKJISYO=NO"
	@${ECHO_MSG} "to argument of make."
	@${ECHO_MSG} "When you want to use skkserv, this option is useful."
	@${ECHO_MSG} "Without it, SKK-JISYO is installed defaultly."
.endif

# install experimantal lisps [handy optional]
#pre-build:
#	@(cd ${WRKSRC} ; \
#		${LN} experimental/skk-abbrev.el . ; \
#		${LN} experimental/skk-dcomp.el . ; \
#		${LN} experimental/skk-hankaku-mode.el . ; \
#		${LN} experimental/skk-jisx0201.el . ; \
#		${LN} experimental/skk-lookup.el . ; \
#		${LN} experimental/skk-study.el . ; \
#	)

post-install:
	@${MAKE} startup-install
	@${MKDIR} ${LOCALBASE}/${SKK_DOCDIR}
	@(cd ${WRKSRC} ;\
		for i in ${EXPERIMENTAL_LISPS} ; do \
			${INSTALL_DATA} $${i} ${LOCALBASE}/${SKK_DOCDIR} ;\
		done ;\
	)
	@install-info ${LOCALBASE}/info/skk.info ${LOCALBASE}/info/dir
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/READMEs/* ${LOCALBASE}/${SKK_DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/experimental/GUIDELINE \
					${LOCALBASE}/${SKK_DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/experimental/dbm/README.dbm \
					${LOCALBASE}/${SKK_DOCDIR}
.endif

startup-install:
	@${INSTALL_DATA} ${FILESDIR}/${SKK_STARTUPEL} \
		${LOCALBASE}/${EMACS_LIBDIR}/site-lisp/skk

.include <bsd.port.post.mk>
