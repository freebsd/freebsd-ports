# New ports collection makefile for:	musicextras
# Date created:		2004-12-18
# Whom:			Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	musicextras
PORTVERSION=	0.6.8
PORTREVISION=	5
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.divineinvasion.net/musicextras/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Automatically retrieving extra information for songs

RUN_DEPENDS=	${RUBY_SITELIBDIR}/mp3info.rb:${PORTSDIR}/audio/ruby-mp3info \
		${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_FEATURES=	iconv
USE_BZIP2=	yes
USE_GETTEXT=	yes

.include <bsd.port.mk>
