# New ports collection makefile for:	skk-elisp
# Version required:	9.6
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/12/15 15:22:45 kuriyama Exp $
#

DISTNAME=	skk9.6
PKGNAME=	ja-skk-elisp-9.6
CATEGORIES=	japanese elisp
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

BUILD_DEPENDS=	mule:${.CURDIR}/../../editors/mule \
		/nonexistent:${SKK_MASTERDIR}:configure
RUN_DEPENDS=	${PREFIX}/share/skk/${SKKJISYO}:${SKK_MASTERDIR}

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${SKK_MASTERDIR}/work/skk-9.6

# we cannot use skk-9.6 on emacs20
EMACS=		mule
ELISPSUBDIR=	share/${EMACS}/site-lisp/skk

MAKE_ARGS=	SUBDIRS='lisp' EMACS=${EMACS} ELISPDIR=${PREFIX}/${ELISPSUBDIR}
PLIST_SUB=	EMACS=${EMACS} ELISPSUBDIR=${ELISPSUBDIR}

# Our makeinfo can't handle files with Japanese characters. :<
#pre-build:
#	(cd ${WRKSRC}/doc; \
#	  /usr/bin/makeinfo --no-split skk.texi)

post-install:
	(cd ${WRKSRC}; make SUBDIRS='doc' install)
	(cd ${WRKSRC}; make SUBDIRS='etc' install)

	@if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	install-info ${PREFIX}/info/skk.info ${PREFIX}/info/dir

.include <bsd.port.mk>
