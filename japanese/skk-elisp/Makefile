# New ports collection makefile for:	skk-elisp
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skk-elisp
PORTVERSION=	9.6
CATEGORIES=	japanese elisp
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
DISTNAME=	skk${PORTVERSION}

MAINTAINER=	matusita@FreeBSD.org

BUILD_DEPENDS=	mule:${.CURDIR}/../../editors/mule
RUN_DEPENDS=	${LOCALBASE}/share/skk/${SKKJISYO}:${SKK_MASTERDIR}

GNU_CONFIGURE=	YES

SKKJISYO_SIZE?=	L
SKKJISYO?=	SKK-JISYO.${SKKJISYO_SIZE}
SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${WRKDIR}/skk-${PORTVERSION}

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
	install-info ${PREFIX}/info/skk.info ${PREFIX}/info/dir

.include <bsd.port.mk>
