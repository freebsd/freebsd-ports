# New ports collection makefile for:	files except executables for mule
# Date created:		7 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mule-common
PORTVERSION=	${MULE_VERSION}
PORTREVISION=	4
CATEGORIES=	editors japanese
MASTER_SITES=	ftp://ftp.m17n.org/pub/mule/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/mule/ \
		http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/mule/
DISTFILES=	mule-${MULE_VERSION}-${EMACS_VERSION}.tar.gz \
		mule-${MULE_VERSION}-${EMACS_VERSION}.patch-981002.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	For a multilingual emacs, emacs lisp files, info pages, etc (except executables)

MULE_VERSION=	2.3
EMACS_VERSION=	19.34

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

WRKDIRBASE=	${WRKDIRPREFIX}${.CURDIR:S,/editors/mule-common$,,}

.for dir in 	chinese/mule-freewnn \
		editors/mule \
		japanese/mule-canna \
		japanese/mule-canna+freewnn \
		japanese/mule-canna+freewnn+sj3 \
		japanese/mule-canna+sj3+wnn6 \
		japanese/mule-canna+sj3+wnn7 \
		japanese/mule-canna+sj3 \
		japanese/mule-canna+wnn6 \
		japanese/mule-canna+wnn7 \
		japanese/mule-freewnn \
		japanese/mule-freewnn+sj3 \
		japanese/mule-sj3 \
		japanese/mule-sj3+wnn6 \
		japanese/mule-sj3+wnn7 \
		japanese/mule-wnn6 \
		japanese/mule-wnn7 \
		korean/mule-freewnn
.if exists(${WRKDIRBASE}/${dir}/work/.build_done.${dir:S,editors/,,:S,chinese/,zh-,:S,japanese/,ja-,:S,korean/,ko-,}-${PORTVERSION}${_SUF1}${_SUF2}.${PREFIX:S/\//_/g})
WRKDIR?=	${WRKDIRBASE}/${dir}/work
MULEPKG?=	${dir:S,editors/,,:S,chinese/,zh-,:S,japanese/,ja-,:S,korean/,ko-,}-${PORTVERSION}${_SUF1}${_SUF2}.${PREFIX:S/\//_/g}
.endif
.endfor
WRKSRC=		${WRKDIR}/mule-${MULE_VERSION}-${EMACS_VERSION}
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/mule.sh

EXTRACT_COOKIE=		${WRKDIR}/.extract_done.${MULEPKG}
CONFIGURE_COOKIE=	${WRKDIR}/.configure_done.${MULEPKG}
BUILD_COOKIE=		${WRKDIR}/.build_done.${MULEPKG}
PATCH_COOKIE=		${WRKDIR}/.patch_done.${MULEPKG}
TMPPLIST=	${WRKDIR}/.PLIST.mktmp-${PKGNAME}
PLIST_SUB=	EMACS_VERSION=${EMACS_VERSION} EMACS_ARCH=${CONFIGURE_TARGET}

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
EMACS_PREFIX=	mule
EMACS_EXECUTABLE =	mule
CONFIGURE_ARGS=	--with-executable=${EMACS_EXECUTABLE} \
		--with-emacs-prefix=${EMACS_PREFIX} \
		--with-terminal-face \
		--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
STRIP=
MAN1=		coco.1 ctags.1 etags.1 m2ps.1 emacs.1 mule.1

INSTALL_TARGET=	install-arch-indep

COMP_ELC=	egg.elc wnn-egg.elc sj3-client.elc sj3-egg.elc canna.elc
ELC_DIR=	../lisp

# ORIGINAL, MEW_ORG_PATCH and MEW_PATCH are used for debugging.
#
#   ORIGINAL: original mule 2.3 based on emacs 19.34
#   MEW_ORG_PATCH: apply mew's patches to original mule (http://www.mew.org)
#   MEW_PATCH: apply mew's patch after apply Mr. Katayama's patches
post-extract:
	${CP} ${FILESDIR}/unexfreebsd.c ${WRKSRC}/src
.if !defined(ORIGINAL) && !defined(MEW_ORG_PATCH)
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/takana-${EMACS_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${MKDIR} ${WRKSRC}/lisp/its
	${CP} ${WRKDIR}/lisp/its/* ${WRKSRC}/lisp/its/
.endif

.if !defined(ORIGINAL)
post-patch:
.if !defined(MEW_ORG_PATCH)
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/patch-${EMACS_VERSION}
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/Mule-${MULE_VERSION}-${EMACS_VERSION}.patch
	cd ${WRKSRC}; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/extra.patch
.if defined(MEW_PATCH)
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/egg.el-${EMACS_VERSION}.patch-for_katayama
.endif
.else
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/egg.el-${EMACS_VERSION}.patch
.endif
.if defined(MEW_PATCH) || defined(MEW_ORG_PATCH)
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/canna.el-${EMACS_VERSION}.patch
	cd ${WRKSRC}/lisp; ${PATCH} --forward --quiet -E -p0 < ${WRKDIR}/mew/sj3-egg.el.patch
.endif
.endif

.if !defined(WRKDIR)
.if defined(PACKAGE_BUILDING)
# XXX
WRKDIR=	${WRKDIRBASE}/editors/mule/work
pre-build::
	@cd ${.CURDIR}/../mule; make
.else
IGNORE=		First you should build install a port for mule except mule-common
.endif
.endif

pre-build::
	${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;
	${RM} -f ${WRKSRC}/etc/DOC* ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${EMACS_VERSION}.*

post-build:
# bytecompile elisps for Japanese input method
	for file in ${COMP_ELC}; do \
		target="$$target ${ELC_DIR}/$$file"; \
	done; \
	cd ${WRKSRC}/src; \
	./temacs -batch -l mule-inst.el $$target

post-install:
# DOC* must be installed by a port for mule except mule-common
	${RM} ${PREFIX}/share/mule/19.34/etc/DOC
	${RM} ${PREFIX}/share/mule/19.34/etc/DOC-19.34.1
# note that any2ps rcs-checkin are scripts
.for file in b2m coco ctags emacsclient etags m2ps
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
	if [ ! -f ${PREFIX}/share/mule/${EMACS_VERSION}/info/dir ]; then \
	  ${MKDIR} ${PREFIX}/share/mule/${EMACS_VERSION}/info; \
	fi
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# Our makeinfo can't handle files with Japanese characters. :<
	install-info --section="The Emacs editor and associated tools" --entry="* Antenews-jp: (antenews-jp).	Version 19 Antenews. (Japanese)" ${PREFIX}/info/antenews-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Mule: (mule).			Multilingual Enhancement to GNU Emacs." ${PREFIX}/info/mule ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Mule-jp: (mule-jp).		Multilingual Enhancement to GNU Emacs. (Japanese)" ${PREFIX}/info/mule-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Egg-jp: (egg-jp).		Japanese/Chinese Inputting Method. (Japanese)" ${PREFIX}/info/egg-jp ${PREFIX}/info/dir
	install-info --section="The Emacs editor and associated tools" --entry="* Canna-jp: (canna-jp).		Another Japanese Inputting Method. (Japanese)" ${PREFIX}/info/canna-jp ${PREFIX}/info/dir
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
	if [ ! -f ${STARTUP_SCRIPT} ]; then \
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/mule.sh ${STARTUP_SCRIPT}; \
	fi

post-package:
	@${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}

.include <bsd.port.post.mk>
