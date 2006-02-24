# New ports collection makefile for:	ja-tomoe
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomoe
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=tomoe/16048

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Tegaki Online MOji-ninshiki Engine

USE_GNOME=	lthack gnomehack
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes

PLIST_DIRS=	include/tomoe share/tomoe
PLIST_FILES=	bin/tomoe bin/tomoe1 include/tomoe/tomoe.h \
		lib/libtomoe.a lib/libtomoe.la \
		lib/libtomoe.so lib/libtomoe.so.1 \
		libdata/pkgconfig/tomoe.pc \
		share/tomoe/all.tdic share/tomoe/hiragana.tdic

.include <bsd.port.mk>
