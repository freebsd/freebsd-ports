# New ports collection makefile for:	pure (for xemacs21-mule)
# Date Created:		4 May 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../pure-emacs20

EMACS_PORT_NAME=	xemacs21-mule
LISPDIR=		${EMACS_LIBDIR}/site-packages/lisp/${PORTNAME}
EMACS_ONLY=		"@comment "
XEMACS_ONLY=		""
ALL_TARGET=		package c
INSTALL_TARGET=		install-package
PUREBIN=		${EMACS_LIBDIR}/site-packages/etc/pure
MAKE_ENV=		LANG=ja_JP.eucJP

.include "${MASTERDIR}/Makefile"
