# New ports collection makefile for:	custom for emacs
# Version required:	1.9962
# Date created:		27 December 1998
# Whom:			shige
#
# $FreeBSD$
#

DISTNAME=	custom-${CUSTOM_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/Staff/Per.Abrahamsen/custom/ \
		ftp://ftp.win.ne.jp/pub/word/elisp/

MAINTAINER?=	shige@FreeBSD.org

# custom library
CUSTOM_VER=	1.9962
CUSTOMDOCDIR=	share/doc/custom
CUSTOM_ELS=	cus-edit.el cus-face.el custom.el \
		wid-browse.el wid-edit.el widget-example.el widget.el

# This is a master port.
PORTCLASS?=	master

.if (${PORTCLASS} == "master")
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=	share/${EMACS_NAME}
HAVE_COMMON_PORT= NO
.endif

.if defined(EMACS_PORT)
PKGNAME=	custom-${EMACS_PORT}-${CUSTOM_VER}
EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}
BUILD_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.if defined(HAVE_COMMON_PORT) && (${HAVE_COMMON_PORT} == "YES")
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
SCRIPTS_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER}
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER=${EMACS_VER} \
		CUSTOMDOCDIR=${CUSTOMDOCDIR}
MAKE_FLAGS=	EMACS=${EMACS_CMD}
.else
.BEGIN:
	@${ECHO} "Error: Bad port."
	@${ECHO} "You must define EMACS_NAME, EMACS_PORT, EMACS_VER, EMACS_LIBDIR."
	@${FALSE}
.endif


do-install:
	@for i in ${CUSTOM_ELS} ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} \
			${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/ ; \
		${INSTALL_DATA} ${WRKSRC}/$${i}c \
			${PREFIX}/${EMACS_LIBDIR}/${EMACS_VER}/site-lisp/ ; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${CUSTOMDOCDIR}
	@for i in ChangeLog TODO ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${CUSTOMDOCDIR} ; \
	done
.endif

.include <bsd.port.mk>
