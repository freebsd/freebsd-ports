# New ports collection makefile for:	pure (for emacs20)
# Date Created:		3 May 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	pure
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	irc elisp
MASTER_SITES=	ftp://ftp.fan.gr.jp/pub/elisp/irchat-pj/2.5/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	pure-${PORTVERSION}p

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

EMACS_PORT_NAME?=	emacs20
LISPDIR?=	${EMACS_LIBDIR}/site-lisp/${PORTNAME}
EMACS_ONLY?=	""
XEMACS_ONLY?=	"@comment "
PUREBIN?=	bin

PLIST_SUB=	LISPDIR=${LISPDIR} \
		EMACS_ONLY=${EMACS_ONLY} \
		XEMACS_ONLY=${XEMACS_ONLY} \
		PUREBIN=${PUREBIN}

.include <bsd.port.mk>
