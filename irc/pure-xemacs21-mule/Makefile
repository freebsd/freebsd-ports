# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../pure-emacs21

BROKEN=		fails to install

USE_EMACS=	yes
EMACS_PORT_NAME=	xemacs21-mule
LISPDIR=		${EMACS_LIBDIR}/site-packages/lisp/${PORTNAME}
EMACS_ONLY=		"@comment "
XEMACS_ONLY=		""
ALL_TARGET=		package c
INSTALL_TARGET=		install-package
PUREBIN=		${EMACS_LIBDIR}/site-packages/etc/pure
MAKE_ENV=		LANG=ja_JP.eucJP

.include "${MASTERDIR}/Makefile"
