# New ports collection makefile for:	ja-netscape7
# Date created:				2002-03-04
# Whom:					trevor
# based on the german/linux-netscape6 port by Thomas E. Zander
#
# $FreeBSD$
#

PKGNAMEPREFIX=	ja-
PORTVERSION=	7.1
CATEGORIES=	japanese www linux
MASTER_SITE_SUBDIR=	${DIST_SUBDIR}/unix/linux22/jgksyc
DISTFILES=	browser.xpi \
		defljajp.xpi \
		flash.xpi \
		langjajp.xpi \
		mail.xpi \
		psm.xpi \
		regjp.xpi \
		regus.xpi \
		spellchecker.xpi \
		talkback.xpi \
		xpcom.xpi

FORBIDDEN="http://vuxml.freebsd.org/c1d97a8b-05ed-11d9-b45d-000c41e2cdad.html"

NETSCAPE_LANG=	japanese

.include "../../www/netscape7/Makefile"
