# New ports collection makefile for:	custom for emacs
# Date created:		27 December 1998
# Whom:			shige
#
# $FreeBSD$
#

PORTNAME=	custom
PORTVERSION=	${CUSTOM_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/Staff/Per.Abrahamsen/custom/ \
		ftp://ftp.win.ne.jp/pub/word/elisp/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	The Custom Library for emacs

# custom library
CUSTOM_VER=	1.9962
CUSTOMDOCDIR=	share/doc/custom
CUSTOM_ELS=	cus-edit.el cus-face.el custom.el \
		wid-browse.el wid-edit.el widget-example.el widget.el

# This is a master port.
PORTCLASS?=	master

.if (${PORTCLASS} == "master")
EMACS_PORT_NAME=	emacs19
.endif

PLIST_SUB=	CUSTOMDOCDIR=${CUSTOMDOCDIR}

.include <bsd.port.pre.mk>

.if !defined(EMACS_PORT_NAME)
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_PORT_NAME."
	@${FALSE}
.endif


do-install:
	@for i in ${CUSTOM_ELS} ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
			${LOCALBASE}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/ ; \
		${INSTALL_DATA} ${WRKSRC}/$${i}c \
			${LOCALBASE}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/ ; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${LOCALBASE}/${CUSTOMDOCDIR}
	@for i in ChangeLog TODO ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${LOCALBASE}/${CUSTOMDOCDIR} ; \
	done
.endif

.include <bsd.port.post.mk>
