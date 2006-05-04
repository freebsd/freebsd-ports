# New ports collection makefile for:    prcs
# Date created:         17 Sep 96
# Whom:                 jmacd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	prcs
PORTVERSION=	1.3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Project Revision Control System

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.3

MAN1=		prcs.1
INFO=		prcs
PLIST_FILES=	bin/prcs

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/emacs)
MAN1+=		prcs-callback.1 prcs-ediff.1 prcs-emerge.1
PLIST_FILES+=	bin/prcs-callback bin/prcs-ediff bin/prcs-emerge \
		share/emacs/site-lisp/prcs.el \
		share/emacs/site-lisp/prcs.elc \
		share/emacs/site-lisp/prcs-ediff.el \
		share/emacs/site-lisp/prcs-ediff.elc \
		share/emacs/site-lisp/prcs-hooks.el \
		share/emacs/site-lisp/prcs-hooks.elc
.endif

post-patch:
	${REINPLACE_CMD} -Ee 's,#!/usr/local/bin/perl5?,#!${PERL},g' \
		${WRKSRC}/emacs/prcs-*

pre-configure:
.if !exists(${LOCALBASE}/bin/emacs)
	${REINPLACE_CMD} -Ee "s@^(SUBDIRS = .*) emacs (.*)@\1 \2@" \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
